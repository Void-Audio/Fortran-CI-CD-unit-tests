import os
import sys

FORTRAN_DIR = os.path.join(os.getcwd(), "kernel")


def rename_so_files(directory, undo=False):

    for filename in os.listdir(directory):
        file_path = os.path.join(directory, filename)

        if os.path.isfile(file_path) and filename.endswith(".so"):
            if undo:
                if filename.startswith("lib"):
                    new_filename = filename[3:] 
                    new_file_path = os.path.join(directory, new_filename)
                    os.rename(file_path, new_file_path)
                    print(f"Undone: {filename} -> {new_filename}")
                else:
                    print(f"Skipping: {filename} doesn't have the 'lib' prefix")
            else:
                if not filename.startswith("lib"):
                    new_filename = "lib" + filename
                    new_file_path = os.path.join(directory, new_filename)
                    os.rename(file_path, new_file_path)
                    print(f"Renamed: {filename} -> {new_filename}")
                else:
                    print(f"Skipping: {filename} already has the 'lib' prefix")
           

if __name__ == "__main__":
    undo_flag = "--undo" in sys.argv
    rename_so_files(FORTRAN_DIR, undo=undo_flag)
