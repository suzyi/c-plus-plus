import os
import glob

if __name__=="__main__":
    file_name = "img_list.txt"
    if os.path.exists(file_name):
        os.remove(file_name)
    with open(file_name, "a") as txt:
        for digit in range(3):
            img_names = glob.glob(f"{digit}/*.png")
            for img_name in img_names:
                txt.write(f"{img_name} {digit}\n")
    print("done")