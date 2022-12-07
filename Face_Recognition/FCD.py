import face_recognition, os
from PIL import Image


print(os.getcwd())

print(os.getcwd())
known_dir = os.listdir("C:\\Users\\efpla\\OneDrive\\Masaüstü\\Projeler\\Face_Recognition\\Known")
unknown_dir = os.listdir("C:\\Users\\efpla\\OneDrive\\Masaüstü\\Projeler\\Face_Recognition\\Unknown")
print(len(unknown_dir))
known_counter = 0
while known_counter < len(known_dir):
    os.chdir("C:\\Users\\efpla\\OneDrive\\Masaüstü\\Projeler\\Face_Recognition\\Known")
    known = known_dir[known_counter]
    print(known)
    image = face_recognition.load_image_file(known)
    encoding = face_recognition.face_encodings(image)[0]
    unknown_counter = 0
    while unknown_counter < len(unknown_dir):
        os.chdir("C:\\Users\\efpla\\OneDrive\\Masaüstü\\Projeler\\Face_Recognition\\Unknown")
        unknown = unknown_dir[unknown_counter]
        unk_img = face_recognition.load_image_file(unknown)
        number = face_recognition.face_locations(unk_img)
        
        if len(number)> 1:
            face_c = 0
            while  face_c < len(number):
                
                enc_unk = face_recognition.face_encodings(unk_img)[face_c]
                results_m = face_recognition.compare_faces([encoding],enc_unk)
                if results_m[0] == False:
                    face_c += 1
                    if face_c == len(number):
                        print(unknown," dosyasındaki fotoğrafta ", known," dosyasındaki kişinin bir fotoğrafı yoktur")
                        unknown_counter += 1
                        print(unknown_counter)
                        break
                else:
                    print(unknown," dosyasındaki fotoğrafta ",known," dosyasındaki kişinin bir fotoğrafı vardır")
                    unknown_counter += 1
                    print(unknown_counter)
                    break
        else:
            enc_unk = face_recognition.face_encodings(unk_img)[0]
            results = face_recognition.compare_faces([encoding],enc_unk)

            if results[0] == True:
                print(unknown," dosyasındaki fotoğraf ", known," dosyasındaki kişinin fotoğrafıdır")
            else:
                print(unknown," dosyasındaki fotoğraf ", known," dosyasındaki kişinin fotoğrafı değildir")
            unknown_counter += 1
            print(unknown_counter)
    known_counter += 1
