import os # system('cls')
import msvcrt # getch()
import getpass # getpass()

# 버스 정보
Buss = ["서울행", "대전행", "대구행", "부산행", "제주행"] # 행선지 정보 배열



# 로그인 form
_stack = 0
while True:
	print("\n\n\n\n\t\t\t===================  LOGIN FORM  ===================\n")
	username = input("\n\t\t\t\t\tENTER USERNAME:\t")
	password = getpass.getpass("\n\t\t\t\t\tENTER PASSWORD:\t")

	if username == "root" and password == "pass": # root 로그인 성공시
		print("\n\n\n\t\t\tWELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL")
		print("\n\n\n\t\t\t\t\tPress any key to continue...")
		msvcrt.getch() # /holds the screen
		os.system('cls') # C언어(sys.cls
		break
	else: # 로그인 실패시
		print("\n\n\n\t\t\tSORRY !!!!  LOGIN IS UNSUCESSFUL")
		print("\n\n\n\t\t\t\t\tPress any key to Retry...")
		_stack += 1
		msvcrt.getch() # holds the screen
		os.system('cls') # C언어(sys.cls

	if _stack == 3: # 로그인 3회 실패시
		print("\n\n\n\nSorry you have entered the wrong username and password for ", _stack , "times!!!\n")
		#print("\n회원 가입으로 이동합니다.\n")
		print("\n\n\n\t\t\t\t\tPress any key to continue...")
		msvcrt.getch() # holds the screen
		os.system('cls') # C언어(sys.cls
		break




while True:
	os.system('cls') # C언어(sys.cls
	print("\n\n\n====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n")
	print("\t\t\t\t\t[1]=> View Bus List\n")
	print("\n\t\t\t\t\t[2]=> Book Tickets\n")
	print("\n\t\t\t\t\t[3]=> Cancle Booking\n")
	print("\n\t\t\t\t\t[4]=> Bus Status Board\n")
	print("\n\t\t\t\t\t[5]=> Exit\n\n")
	print("===============================================================================================================\n\n")
	_ChoseService = input("\t\t\tEnter Your Choice:: ")




	if _ChoseService == '1':
		os.system('cls') # C언어(sys.cls
		print("\n\n\n=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n")
		
		_stack = 0
		for item in Buss:
			print("\t\t\t\t\t[No." , (_stack + 1) , "번 BUS]    KOSTA -> " , Buss[_stack] , "\n\n")
			_stack += 1

		print("\n\n\n\t\t\t\t\tPress any key to Move back...")
		msvcrt.getch() # C언어 _getch()
		os.system('cls') # C언어(sys.cls




	if _ChoseService == '5':
		os.system('cls') # C언어(sys.cls
		print("---------------------------------------------------------------------------------------------------------------\n\n")
		print("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\n")
		print("---------------------------------------------------------------------------------------------------------------\n\n")
		print("\t\t\t\t\t\t\t\t\t\tMade by Lee_kyungwon")
		print("\n\n\n\t\t\t\t\tPress any key to Exit...\n\n\n")
		msvcrt.getch() # C언어 _getch()
		os.system('cls') # C언어(sys.cls
		break