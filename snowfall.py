#Snowfall App
#Franklin Smith

import json
import argparse
import requests
import urllib.request
import urllib.parse
import re
import codecs
import time
import webbrowser
import urllib


#import urllib2
reader = codecs.getreader("utf-8")

import json
from urllib.request import urlopen


def data_function():
	"""
	This function will get the data information
	from the different resorts. Right now I am 
	planning on getting the snowfall in the last
	24 hours, 72 hours, base snow, temperature, 
	and state when that information was last updated.

	"""
	
	#skibowl
	skibowl_url = "http://www.skibowl.com/winter/mt-hood-weather-conditions"
	skibowl_values = {"s": "basics", "submit":"search"}
	skibowl_data = urllib.parse.urlencode(skibowl_values)
	skibowl_data = skibowl_data.encode("utf-8")
	skibowl_req = urllib.request.Request(skibowl_url,skibowl_data)
	skibowl_resp = urllib.request.urlopen(skibowl_req)
	skibowl_respData = skibowl_resp.read()
	#print(respData)
	#between line 457 and 503
	
	print("Ski Bowl")
	skibowl_paragraphs = re.findall(r"<td class=(.*?)</td>",str(skibowl_respData))
	for line in skibowl_paragraphs:
		#print(line)
		if 'label' in line:
			print(line[8:].replace("<br/>",""))
		if 'info' in line:
			print(line[7:])
		if '"">' in line:
			line.strip("</br>")
			print(line[3:])


	#mthood meadows (pause)
	"""
	url = "https://www.skihood.com/the-mountain/conditions"
	values = {"s": "basics", "submit":"search"}
	data = urllib.parse.urlencode(values)
	data = data.encode("utf-8")
	req = urllib.request.Request(url,data)
	resp = urllib.request.urlopen(req)
	respData = resp.read()
	#print(respData)
	temp = []
	#want line 491 to 528
	print("Mt.Hood Meadows")
	meadows_paragraphs = re.findall(r"<dt(.*?)</dt>",str(respData))
	meadows_info = re.findall(r"<dd(.*?)</dd>",str(respData))
	print(meadows_paragraphs)
	print(meadows_info)
	print(meadows_paragraphs[0][17:])
	"""
	
	#for line in meadows_paragraphs:
		#if "metric" in line:
			#print(line)
		#if "depth" in line:
			#print(line)
		


	#print(info)


	
	
		








def main():
	"""
	The main function calls all of the above functions in the file
	"""
	data_function()
if __name__ == "__main__":
	main()