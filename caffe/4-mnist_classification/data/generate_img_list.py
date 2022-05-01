import os
import glob

if __name__=="__main__":
    for mode in ["train", "test"]:
        file_name = mode + "_list.txt"
        if os.path.exists(file_name):
            os.remove(file_name)
        with open(file_name, "a") as txt:
            for digit in range(3):
                img_names = glob.glob(f"{mode}\{digit}/*.png")
                for img_name in img_names:
                    txt.write(f"{img_name} {digit}\n")
    print("done")