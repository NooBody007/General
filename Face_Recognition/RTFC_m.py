import cv2,face_recognition,os,pyautogui,time
from PIL import Image
import numpy as np


#Enter "Known" file.
os.chdir("Known")
print(os.getcwd())

#Scan the "Known" file and append the encodings of the faces to numpy array(or list).
known_enc = []
known_dir = os.listdir()
known_len = len(os.listdir())
known_ind = 0
while known_ind < known_len:
    print(known_dir[known_ind])
    load = face_recognition.load_image_file(known_dir[known_ind])
    encode = face_recognition.face_encodings(load)[0]
    known_enc.append(encode)
    known_ind += 1

known_lst = []

for known in known_dir:
    new = known.split(".")
    new2 = new[0].split("_")
    print(new2)
    name = new2[0] + " " + new2[1]
    print(name)
    known_lst.append(name)

print(known_lst)






#Describe webcam and face capture frame
cam = cv2.VideoCapture(0)

process_this_frame = True

while True:
    p,frame = cam.read()
    small_frame = cv2.resize(frame,(0,0), fx=0.25, fy=0.25)
    rgb_small_frame = small_frame[:, :, ::-1]
    
    if process_this_frame:
        face_locations = face_recognition.face_locations(rgb_small_frame)
        face_encodings = face_recognition.face_encodings(rgb_small_frame,face_locations)

        face_names = []
        for face_encoding in face_encodings:
            match = face_recognition.compare_faces(known_enc,face_encoding)
            name = "Unknown"
            face_distances = face_recognition.face_distance(known_enc, face_encoding)
            best_match_index = np.argmin(face_distances)
            print(match[best_match_index])
            if match[best_match_index]:
                name = known_lst[best_match_index]
                face_names.append(name)
            else:
                face_names.append(name)
                t = time.localtime()
                unk_time = str(t.tm_mday) + "." + str(t.tm_mon) + "." + str(t.tm_year) + "-" + str(t.tm_hour) + "_" + str(t.tm_min) + "_" + str(t.tm_sec) + ".png"
                os.chdir("..")
                os.chdir("ss")
                print(unk_time)
                ss = pyautogui.screenshot(unk_time)
                #C:/Users/efpla/OneDrive/Masaüstü/Projeler/Face_Recognition/ss
                print(unk_time)
        print(face_names)
        
    
    process_this_frame = not process_this_frame

    for (top, right, bottom, left), name in zip(face_locations, face_names):
        top *= 4
        right *= 4
        bottom *= 4
        left *= 4

        cv2.rectangle(frame,(left,top),(right,bottom),(0,0,255),2)
        cv2.rectangle(frame,(left,bottom-35),(right,bottom),(0,0,255),cv2.FILLED)
        font = cv2.FONT_HERSHEY_DUPLEX
        cv2.putText(frame,name,(left+6, bottom-6),font,1.0,(255,255,255),1)

    cv2.imshow('Video',frame)

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

cam.release()
cv2.destroyAllWindows()






"""cam = cv2.VideoCapture(0)


cam.read()
cam.release()"""
