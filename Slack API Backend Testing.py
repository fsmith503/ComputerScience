#Author Franklin Smith
#Date November 22nd 2016
#Title:
"""

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
    upload_json_obj = urllib.request.urlopen("https://slack.com/api/files.upload?token=(token_number_goes_here_without_parentheses)&content=C:\\Users\\Franklin\\Desktop\\blackpane.png&filename=planepic&pretty=1")
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
    json_obj = urllib.request.urlopen("https://slack.com/api/files.list?token=(token_number_goes_here_without_parentheses)&pretty=1")
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
    files_delete = {"file" : x , "token" : "(token_number_goes_here_without_parentheses)"}
    files_delete_request = requests.delete("https://slack.com/api/files.delete", params=files_delete)
    if "true" in files_delete_request.text:
        print("The file you uploaded was sucsessfully deleted")
    else:
        print("The file you uploaded wasnt sucsessfully deleted")
    files_delete_false_file_request_params = {"file" : "012345" , "token" : "(token_number_goes_here_without_parentheses)"}
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

