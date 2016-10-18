import numpy as np
import cv2 as cv

def main():
    cap = cv.VideoCapture(0)

    while(True):
        # Capture frame-by-frame
        ret, frame = cap.read()

        # Our operations on the frame come here
        # gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

        lower_white = np.array([255,255,255])
        upper_white = np.array([255,255,255])

        mask = cv.inRange(frame, lower_white, upper_white)
        if cv.countNonZero(mask) == 0:
            continue # will put servo task here

        # Display the resulting frame
        cv.imshow('frame', frame)
        cv.imshow('mask', mask)
        # displayWindows([frame, mask])

        if cv.waitKey(1) & 0xFF == ord('q'):
            break

    # When everything done, release the capture
    cap.release()
    cv.destroyAllWindows()

def displayWindows(windows):
    n = len(windows)
    x, y, z = windows[0].shape
    # display = 
    print cv.namedWindow('hi', cv.WINDOW_NORMAL)
    for j in range(y):
        for i in range(n*x):
            for index in range(n):
                display[i,j] = windows[index][i - index*x, j]
    cv.imshow('frame', display)


main()