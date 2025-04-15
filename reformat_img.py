import os
 
curr_dir = os.path.dirname(__file__)
img_dir= os.path.join(curr_dir, './img')

def ls_files(dir):
    return os.listdir(dir)

if __name__=="__main__":
    for img in ls_files(img_dir):
        if ' ' in img:
            print(img)
            tokens=img.strip().split(' ')
            new_img_name="_".join(tokens)
            old_path=os.path.join(img_dir,img)
            new_path=os.path.join(img_dir,new_img_name)
            try:
                os.rename(old_path,new_path)
                print(f'changing {img} to {new_img_name}')
            except:
                print('Failed!')
    

