import os # system('cls')
import msvcrt # getch()
import getpass # getpass()

# 버스 정보
Buss = ["서울행", "대전행", "대구행", "부산행", "제주행"] # 행선지 정보 배열
Bus_fileName = [ "bus1.txt", "bus2.txt", "bus3.txt", "bus4.txt", "bus5.txt" ] # 각 버스별, 좌석 현황 텍스트 파일名
Seats = 40 # 버스 좌석 수




def ViewBusList():
	os.system('cls') # C언어(sys.cls
	print("\n\n\n=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n")


	HowManyBus = int(0)
	for item in Buss:
		print("\t\t\t\t\t[No." , (HowManyBus + 1), "번 BUS]    KOSTA -> " , Buss[HowManyBus] , "\n\n")
		HowManyBus += 1




def SeatFileOpenReadMode(_ChoseBusNum):
	try:
		f = open(Bus_fileName[(_ChoseBusNum - 1)], "rt", encoding="utf-8")
	except: # 선택한 버스의 파일이 없을시
		f = open(Bus_fileName[(_ChoseBusNum - 1)], "wt", encoding="utf-8") # 파일 생성

		for turn in range(Seats):
			f.write("%d" % 0)
			
		f.close()
		f = open(Bus_fileName[(_ChoseBusNum - 1)], "rt", encoding="utf-8") # 텍스트 읽기 모드로 파일 open

	p = f.readline()

	f.close() # open 용무 종료

	return p # ' readline() ' 으로 읽어온 문자열을 retur




def ViewBusSeats(_ChoseBusNum, p):
	os.system('cls') # C언어(sys.cls
	print("____________________________________________________________________________________________________________________\n")
	print("                                      Bus.No   ", _ChoseBusNum, "번     ", Buss[(_ChoseBusNum - 1)])
	print("\n\t\t\t* 1번 ~ 10번 좌석은 교통 약자를 위해 배려해 주세요 :)\n")
	print("____________________________________________________________________________________________________________________")
	for i in range(Seats):
		
		if i%10 == 0: # form 줄내림(시각 효과
			print("\n")

		if p[i] == '0': # 예약 가능 좌석
			print("\t%2d.Empty\t" % (i+1))
		elif p[i] == '1': # 예약 불가 좌석
			print("\t%2d.Full\t" % (i+1))




def SeatFileWriteAddMode(_newSeatsTxt, _ChoseBusNum):
	# 파일 내용 새로 입력
	f = open(Bus_fileName[(_ChoseBusNum - 1)], "wt", encoding="utf-8")
	f.write(_newSeatsTxt)	
	f.close()









## 로그인 form
#_stack = 0
#while True:
#	print("\n\n\n\n\t\t\t===================  LOGIN FORM  ===================\n")
#	username = input("\n\t\t\t\t\tENTER USERNAME:\t")
#	password = getpass.getpass("\n\t\t\t\t\tENTER PASSWORD:\t")

#	if username == "root" and password == "pass": # root 로그인 성공시
#		print("\n\n\n\t\t\tWELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL")
#		print("\n\n\n\t\t\t\t\tPress any key to continue...")
#		msvcrt.getch() # /holds the screen
#		os.system('cls') # C언어(sys.cls
#		break
#	else: # 로그인 실패시
#		print("\n\n\n\t\t\tSORRY !!!!  LOGIN IS UNSUCESSFUL")
#		print("\n\n\n\t\t\t\t\tPress any key to Retry...")
#		_stack += 1
#		msvcrt.getch() # holds the screen
#		os.system('cls') # C언어(sys.cls

#	if _stack == 3: # 로그인 3회 실패시
#		print("\n\n\n\nSorry you have entered the wrong username and password for ", _stack , "times!!!\n")
#		#print("\n회원 가입으로 이동합니다.\n")
#		print("\n\n\n\t\t\t\t\tPress any key to continue...")
#		msvcrt.getch() # holds the screen
#		os.system('cls') # C언어(sys.cls
#		break




while True:
	# 초기 화면
	os.system('cls') # C언어(sys.cls
	print("\n\n\n====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n")
	print("\t\t\t\t\t[1]=> View Bus List\n")
	print("\n\t\t\t\t\t[2]=> Book Tickets\n")
	print("\n\t\t\t\t\t[3]=> Cancle Booking\n")
	print("\n\t\t\t\t\t[4]=> Bus Status Board\n")
	print("\n\t\t\t\t\t[5]=> Exit\n\n")
	print("===============================================================================================================\n\n")
	_ChoseService = input("\t\t\tEnter Your Choice:: ")




	if _ChoseService == '1': # View List
		ViewBusList()
		print("\n\n\n\t\t\t\t\tPress any key to Move back...")

		msvcrt.getch() # holds the screen




	if _ChoseService == '2': # Booking
		ViewBusList()
		_ChoseBusNum = int(input("\n\t\t\tEnter the Bus \" Only NUMBER \" :--->\t")) #for entering bus number


		p = list(SeatFileOpenReadMode(int(_ChoseBusNum))) # return 받은 좌석의 현황 문자열을, list형식 변수 p로


		# 버스 좌석 만석 체킹
		full = 0 # 만석 체킹을 위한 변수 == full
		for i in range(Seats):
			if p[i] == '1':
				full += 1

		if full == Seats: # 만석시
			ViewBusSeats(_ChoseBusNum, p) # 현재 좌석 현황 form
			print("\n\t\t\t\t\tThere is no blank seat in this bus")
			print("\n\t--------------------------------------------------\n")
			print("\n\n\n\t\t\t\t\tPress any key to Move back...")

			msvcrt.getch() # /holds the screen
			continue # 초기 화면으로


		ViewBusSeats(_ChoseBusNum, p) # 현재 좌석 현황 form
		_ChoseSeatNum = int(input("\n\n\n\t\t\t\tEnter the seat number:--->\t")) # 예약할 좌석 번호

		# 선택한 좌석 번호 공석 체킹
		if p[int(_ChoseSeatNum) - 1] == '1':
			print("\n\t\t\t\t\t이미 예약된 좌석으로, 예약이 불가합니다.")
			print("\n\t--------------------------------------------------\n")
			print("\n\n\n\t\t\t\t\tPress any key to Move back...")

		elif p[int(_ChoseSeatNum) - 1] == '0':
			p[int(_ChoseSeatNum) - 1] = str(1)
			_newSeatsTxt = ''.join(p) # 새로운 좌석 현황 문자열 생성(왜냐하면, list 형식의 str형식 변환 必

			SeatFileWriteAddMode(_newSeatsTxt, int(_ChoseBusNum))

			ViewBusSeats(_ChoseBusNum, p) # 현재 좌석 현황 form
			print("\n\n\n\t\t\t\t\t%d번 좌석 Booking Success" % _ChoseSeatNum)
			print("\n\t--------------------------------------------------\n")
			print("\n\n\n\t\t\t\t\tPress any key to Move back...")

		msvcrt.getch() # /holds the screen
		continue # 초기 화면으로




	if _ChoseService == '3': # Cancleing
		ViewBusList()
		_ChoseBusNum = int(input("\n\t\t\tEnter the Bus \" Only NUMBER \" :--->\t")) #for entering bus number


		p = list(SeatFileOpenReadMode(int(_ChoseBusNum))) # return 받은 좌석의 현황 문자열을, list형식 변수 p로


		# 버스 좌석 체킹
		vacancy = Seats # 체킹을 위한 변수 == vacancy
		for i in range(Seats):
			if p[i] == '1':
				vacancy -= 1

		if vacancy == Seats: # 예약되어 있는 좌석이 없을시
			ViewBusSeats(_ChoseBusNum, p) # 현재 좌석 현황 form
			print("\n\t\t\t\t\t예약된 좌석이 없어, 취소할 내용이 없습니다.")
			print("\n\t--------------------------------------------------\n")
			print("\n\n\n\t\t\t\t\tPress any key to Move back...")

			msvcrt.getch() # /holds the screen
			continue # 초기 화면으로


		ViewBusSeats(_ChoseBusNum, p) # 현재 좌석 현황 form
		_ChoseSeatNum = int(input("\n\n\n\t\t\t\tEnter the seat number:--->\t")) # 예약 취소할 좌석 번호

		# 선택한 좌석 번호 공석 체킹
		if p[int(_ChoseSeatNum) - 1] == '0':
			print("\n\t\t\t\t\t예약 내역이 없는 좌석으로, 예약 취소가 불가합니다.")
			print("\n\t--------------------------------------------------\n")
			print("\n\n\n\t\t\t\t\tPress any key to Move back...")

		elif p[int(_ChoseSeatNum) - 1] == '1':
			p[int(_ChoseSeatNum) - 1] = str(0)
			_newSeatsTxt = ''.join(p) # 새로운 좌석 현황 문자열 생성(왜냐하면, list 형식의 str형식 변환 必

			SeatFileWriteAddMode(_newSeatsTxt, int(_ChoseBusNum))

			ViewBusSeats(_ChoseBusNum, p) # 현재 좌석 현황 form
			print("\n\n\n\t\t\t\t\t%d번 좌석 Cancleing Success" % _ChoseSeatNum)
			print("\n\t--------------------------------------------------\n")
			print("\n\n\n\t\t\t\t\tPress any key to Move back...")

		msvcrt.getch() # /holds the screen
		continue # 초기 화면으로




	if _ChoseService == '5': # Exit
		os.system('cls') # C언어(sys.cls
		print("---------------------------------------------------------------------------------------------------------------\n\n")
		print("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\n")
		print("---------------------------------------------------------------------------------------------------------------\n\n")
		print("\t\t\t\t\t\t\t\t\t\tMade by Lee_kyungwon")
		print("\n\n\n\t\t\t\t\tPress any key to Exit...\n\n\n")
		msvcrt.getch() # C언어 _getch()
		os.system('cls') # C언어(sys.cls
		break # whlie end