def compare_files_bytewise(file1, file2):
    with open(file1, "rb") as f1, open(file2, "rb") as f2:
        return f1.read() == f2.read()

if compare_files_bytewise("file1.vtk", "file2.vtk"):
    print("Dateien sind identisch")
else:
    print("Dateien unterscheiden sich")
