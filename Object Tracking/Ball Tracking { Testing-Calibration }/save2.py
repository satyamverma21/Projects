
import cv2 as cv
import numpy as np

height = 100 ; 

def getBall (frame , _mask , cname ):
    global height
    kernal = np.ones((5, 5), "uint8")
    yellow_mask = cv.dilate(_mask, kernal)
    contours, hierarchy = cv.findContours(yellow_mask, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
    
    
    for pic, contour in enumerate(contours):

        area = cv.contourArea(contour)
        
        #--------------------------------------{ orange calibration and testing }-----------------------------------------------------
        if cname== "orange" and height == 100: 
            print(area)
            cv.putText(frame, str(area) , (10, height),cv.FONT_HERSHEY_SIMPLEX, 1.0, (0, 255, 0))
            area+=200
            
        height = (height+100)%1200
        #-------------------------------------------------------------------------------------------
        
        
        
        if (area > 300):
                x, y, w, h = cv.boundingRect(contour)
                frame = cv.rectangle(frame, (x, y),  (x + w, y + h), (0, 255, 0), 2)
                cv.putText(frame, cname , (x, y),cv.FONT_HERSHEY_SIMPLEX, 1.0, (0, 255, 0))
            


    
def tracKBall(frame, masks):
    
    getBall(frame , masks[0] , "yellow")
    getBall(frame , masks[1] , "green")
    getBall(frame , masks[2] , "orange")
    
   
    cv.imshow("Multiple Color Detection in Real-TIme",
              cv.cvtColor(frame, cv.COLOR_HSV2BGR))








vid = cv.VideoCapture('vid.mp4')  # video
count = 0
print(vid.get(cv.CAP_PROP_FPS))

while 1:

    # reading video frame by frame
    get, frame = vid.read()
    frame = cv.resize(frame, (600, 350))
    frame = cv.cvtColor(frame, cv.COLOR_BGR2HSV)

    if cv.waitKey(20) == ord('q'):
        break

    # values are calibrated using trackbar // white color is not calibrated yet
    m1 = cv.inRange(frame, (22, 85, 0), (28, 255, 255))  # yellow
    m2 = cv.inRange(frame, (31, 53, 0), (98, 255, 255))  # green
    m3 = cv.inRange(frame, (3, 67, 164), (15, 246, 255))  # orange

    # for testing // white color is not calibrated yet
    # cv.imshow("yellow", m1)  # yellow
    # cv.imshow("green", m2)  # green
    cv.imshow("orange", m3)  # orange

    tracKBall(frame,[m1,m2,m3] ) # 
    


vid.release()
cv.destroyAllWindows()
