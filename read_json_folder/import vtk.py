import vtk
import numpy as np
from vtk.util.numpy_support import vtk_to_numpy


def read_vtk(filename):
    reader = vtk.vtkDataSetReader()
    reader.SetFileName(filename)
    reader.Update()

    data = reader.GetOutput()

    if data is None:
        raise RuntimeError(f"Konnte Datei nicht lesen: {filename}")

    return data


def vtk_array(arr):
    if arr is None:
        return None
    return vtk_to_numpy(arr).copy()


def get_array_names(data, location="point"):
    if location == "point":
        pd = data.GetPointData()
    else:
        pd = data.GetCellData()

    names = []
    for i in range(pd.GetNumberOfArrays()):
        names.append(pd.GetArrayName(i))
    return names


def print_arrays(data, label):
    print(f"\n--- {label} ---")

    pd = data.GetPointData()
    cd = data.GetCellData()

    print("PointData Arrays:", pd.GetNumberOfArrays())
    for i in range(pd.GetNumberOfArrays()):
        arr = pd.GetArray(i)
        print(f"  PD {i}: {arr.GetName()} ({arr.GetNumberOfComponents()})")

    print("CellData Arrays:", cd.GetNumberOfArrays())
    for i in range(cd.GetNumberOfArrays()):
        arr = cd.GetArray(i)
        print(f"  CD {i}: {arr.GetName()} ({arr.GetNumberOfComponents()})")


def compare_arrays(a1, a2, name, tol=1e-6):
    if a1 is None or a2 is None:
        print(f"{name}: fehlt ❌")
        return

    if a1.shape != a2.shape:
        print(f"{name}: Shape mismatch {a1.shape} vs {a2.shape} ❌")
        return

    diff = np.abs(a1 - a2)
    max_diff = np.nanmax(diff)

    if max_diff > tol:
        print(f"{name}: ❌ max diff = {max_diff}")
    else:
        print(f"{name}: ✅")


def compare_dataset_arrays(d1, d2, location="point"):
    if location == "point":
        a1 = d1.GetPointData()
        a2 = d2.GetPointData()
    else:
        a1 = d1.GetCellData()
        a2 = d2.GetCellData()

    names1 = [a1.GetArrayName(i) for i in range(a1.GetNumberOfArrays())]
    names2 = [a2.GetArrayName(i) for i in range(a2.GetNumberOfArrays())]

    print(f"\n--- Vergleich {location.upper()} DATA ---")

    # fehlende Arrays
    for n in names1:
        if n not in names2:
            print(f"{n}: fehlt in File2 ❌")

    for n in names2:
        if n not in names1:
            print(f"{n}: fehlt in File1 ❌")

    # gemeinsame vergleichen
    for n in names1:
        if n in names2:
            arr1 = vtk_array(a1.GetArray(n))
            arr2 = vtk_array(a2.GetArray(n))
            compare_arrays(arr1, arr2, f"{location.upper()}[{n}]")


def compare_points(d1, d2):
    print("\n--- Vergleich POINTS ---")

    p1 = vtk_array(d1.GetPoints().GetData())
    p2 = vtk_array(d2.GetPoints().GetData())

    compare_arrays(p1, p2, "POINTS")


def compare_vtk(file1, file2, debug=True):
    d1 = read_vtk(file1)
    d2 = read_vtk(file2)

    if debug:
        print_arrays(d1, "FILE 1")
        print_arrays(d2, "FILE 2")

    compare_points(d1, d2)
    compare_dataset_arrays(d1, d2, "point")
    compare_dataset_arrays(d1, d2, "cell")


# ▶️ Start
compare_vtk("file1.vtk", "file2.vtk")

