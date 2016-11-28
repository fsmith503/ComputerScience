#Author Franklin Smith
#Date November 22nd 2016
#Title: slack_interview_task.py
"""
The first part of this python program file is
the First task of the interview tasks which is 
endpoint api testing. This file is to be called
from the command line with python and requires 
no parameters.

The second part of this file will be the push 
notification task, where i have been asked to 
provide a high-level description of a system I
would write to rest Slack's push notification 
functionality. This will be commented below,
at the end of this entire file on the bottom.
"""

import json
import argparse
import requests
import urllib.request
import urllib.parse
import urllib
import re
import codecs
import time
import webbrowser
reader = codecs.getreader("utf-8")
x = "hello"


def files_upload():
    """
    files_upload function tests that the uploaded file is 
        no greater than 1 MB in size, Returns a file ID and 
        expected thumbnail URLs
    Args:
        None
    Returns:
        Nothing
    """
    global x
    upload_json_obj = urllib.request.urlopen("https://slack.com/api/files.upload?token=xoxp-108182559271-107571848180-107582841189-7223d14e2041350f81ad1f2238d525be&content=C:\\Users\\Franklin\\Desktop\\blackpane.png&filename=planepic&pretty=1")
    upload_data = json.load(reader(upload_json_obj))
    #print(upload_data)
    x = upload_data["file"]["id"]
    if "name" in upload_data["file"]:
        print("There is a file name returned by the file.upload API endpoint, the name is {}".format(upload_data["file"]["name"]))
    else:
        print("There is no file name returned by the file.upload API endpoint")
    if "id" in upload_data["file"]:
        print("There is a file ID returned by the file.upload API endpoint, the ID is {}".format(upload_data["file"]["id"]))
    else:
        print("There is no file ID returned by the file.upload API endpoint")
    if int(upload_data["file"]["size"]) < 1000000:
        print("The size of your uploaded file is less than 1MB, the size is {} bytes".format(upload_data["file"]["size"]))
    else:
        print("There size of your file is larger than 1MB, please upload a smaller file")
    if "thumb_64" not in upload_data["file"]:
        print("There is no 64 pixel thumbnail returned by the file.upload API endpoint")
    else:
        print("There is a 64 pixel thumbnail returned by the file.upload API endpoint")
    if "thumb_80" not in upload_data["file"]:
        print("There is no 80 pixel thumbnail returned by the file.upload API endpoint")
    else:
        print("There is a 80 pixel thumbnail returned by the file.upload API endpoint")
    if "thumb_360" not in upload_data["file"]:
         print("There is no 360 pixel thumbnail returned by the file.upload API endpoint")
    else:
        print("There is a 360 pixel thumbnail returned by the file.upload API endpoint")
    if "thumb_360_gif" not in upload_data["file"]:
        print("There is no 360 gif pixel thumbnail returned by the file.upload API endpoint")
    else:                    
        print("There is a 360 gif pixel thumbnail returned by the file.upload API endpoint")
    if "thumb_480" not in upload_data["file"]:
        print("There is no 480 pixel thumbnail returned by the file.upload API endpoint")
    else:
        print("There is a 480 pixel thumbnail returned by the file.upload API endpoint") 
    if "thumb_160" not in upload_data["file"]:
        print("There is no 160 pixel thumbnail returned by the file.upload API endpoint")
    else:
        print("There is a 160 pixel thumbnail returned by the file.upload API endpoint")       
    
def files_list():
    """
    files_list function ensures a file we uploaded
        is properly listed in the response with the 
        correct ID, Also lists only by type the "image"
        when calling the endpoint.
    Args:
        None
    Returns:
        Nothing
    """
    print("Please wait momentarily while the program gives the file.list server time to update")
    time.sleep(30)
    json_obj = urllib.request.urlopen("https://slack.com/api/files.list?token=xoxp-108182559271-107571848180-107582841189-7223d14e2041350f81ad1f2238d525be&pretty=1")
    list_data = json.load(reader(json_obj))
    if list_data["files"][0]["id"] == x:
        print("The file you uploaded is properly listed in the response with the correct ID")
    else:
        print("The file you uploaded is not properly listed in the the response with the correct ID")
    count = 0
    print("Below are the ID's of listed files of the type Image")
    for i in list_data["files"]:
        if list_data["files"][count]["filetype"] == "image": #test change image to text
            print(list_data["files"][count]["id"])
            count += 1

def files_delete():
    """
    files_delete function Deletes a file we uploaded
        and confirms it is deleted, Also trys to delete a 
        file that dosent exit and confirms that the correct
        error message occurs
    Args:
        None
    Returns:
        Nothing
    """
    files_delete = {"file" : x , "token" : "xoxp-108182559271-107571848180-107582841189-7223d14e2041350f81ad1f2238d525be"}
    files_delete_request = requests.delete("https://slack.com/api/files.delete", params=files_delete)
    if "true" in files_delete_request.text:
        print("The file you uploaded was sucsessfully deleted")
    else:
        print("The file you uploaded wasnt sucsessfully deleted")
    files_delete_false_file_request_params = {"file" : "012345" , "token" : "xoxp-108182559271-107571848180-107582841189-7223d14e2041350f81ad1f2238d525be"}
    files_delete_false_file_request = requests.delete("https://slack.com/api/files.delete", params=files_delete_false_file_request_params)
    if "file_not_found" in files_delete_false_file_request.text:
        print("You attempted to delete a file that dosent exist")

def main():
    """
    The main function calls all of above functions in the file
    """
    files_upload()
    files_list()
    files_delete()
if __name__ == "__main__": 
    main() 

"""
Task 2 push notification
Question: Provide a high-level description of a system you 
would write to test Slack's push notification functionality. 
We would be able to use this system to test the following

1.Messages that should be pushed to a user's phone are properly detected and marked as "pending" 
in the database — that is, the message is pending a push to the user's mobile device

2.Pending messages are pushed when the user goes offline or has been idle for 15 minutes

3.Pending messages are pushed to all active push tokens that the user's devices 
have registered with us

4.The messages sent to the push notification servers contain the correct content 
and are properly formatted

5.Pushed messages are switched from the "pending" state to the "pushed" state in the DB

push notifications are sent from the server
The slack application server sends a notification to the notification server
which would be an APN, then from the APN the notification goes to the device.
Notification server knows how to send it to the device by registering the token.
Sends a request from the device to the notification server which registers the 
for that device.
Send the token from the device to the application server then store the token in 
the database.
Sends notification with the token from the database to the APN, the APN takes the notification
and sends it to the device.

1. To properly detect the message, I would test the token of the notification and if it matched
with the account and device token then it would be detected.
In the database when the message is pending to be pushed, i would assign a parameter to the 
message, it would be one of two choices (sent or pending), if the message was already sent, I 
would test that sent_message_paramter == sent, if it was pending i would test that
pending_message_parameter == pending.

2. To test the functionality of messages being pushed when the user goes offline or idle,
I would specifically have a parameter that is a message count of pending messages,
so when the login parameter for the user is offline, I would test if the message has been
sent or not. 
if login_parameter == offline:
    send message
Then check the message parameter and reassure that it is sent.
To check if the user has been idle for 15 mintues I would create a login timestamp parameter
and compare that parameter to the current time of the computer. if the difference is 15 minutes
then it would be time to send the message. To check the functionality of the message being
sent i would check if the time difference between the login timestamp and the current time is
15 minutes, is the message status parameter == sent.

3. To check if pending messages are pushed to all push tokens that the users devices have registered
I would get the token information, and examine the message parameters, and i Would check that each 
token is in the message parameter of recipient. For exmaple if the registered tokens are 1,2,3,4,5.
When the message parameter changes from pending to sent, did it send to tkens 1,2,3,4,5.

4. To check the functionality of the messages sent to the push notification servers contain the 
correct content and are properly formatted, I would make a filetype parameter of the message and 
have specfic format methods for those filetypes, I would also verify that the content is that of 
the filetype.
filetype = jpg.
if file_type_of_message != jpg:
    print("error the message didnt contain the correct content")

5. To test that messages are switch from pending state to pushed state in the database, I would 
double check the parameter information from the APN to the database
APN_message#1234_state = pushed
if server_message#1234 != pushed:
    print("The message#1234 was not switched from pending to pushed in the Database")
"""