#SingleInstance force
SetTitleMatchMode, 2

ResizeWin(Width = 0,Height = 0)
{
  WinGetPos,X,Y,W,H,A
  If %Width% = 0
    Width := W

  If %Height% = 0
    Height := H

  WinMove,A,,%X%,%Y%,%Width%,%Height%
}

LeftThird()
{
	WinGetPos, X,Y,W,H,A
	WinMove,A,,0,0,1140,1398
}

MiddleThird()
{
	WinGetPos, X,Y,W,H,A
    WinMove,A,,1142,0,1140,1398
}

RightThird()
{
	WinGetPos, X,Y,W,H,A
	WinMove,A,,2284,0,1140,1398
}

LeftHalf()
{
	WinGetPos, X,Y,W,H,A
	WinMove,A,,0,0,1720,1398
}

RightHalf()
{
	WinGetPos, X,Y,W,H,A
	WinMove,A,,1722,0,1720,1398
}


Middle()
{
	WinGetPos, X,Y,W,H,A
	WinMove,A,,720,100,2000,1200
}

<+F1::
   IfWinExist ahk_exe chrome.exe
	winactivate ahk_exe chrome.exe
   else
        run chrome.exe
   WinWait ahk_exe chrome.exe
   WinActivate ahk_exe chrome.exe  
   WinWaitActive ahk_exe chrome.exe
Return
	
<+F2::
	
   IfWinExist ahk_exe Fusion360.exe
	winactivate ahk_exe Fusion360.exe
   else
        run " ... \Autodesk Fusion 360"
   WinWait ahk_exe Fusion360.exe
   WinActivate ahk_exe Fusion360.exe
   WinWaitActive ahk_exe Fusion360.exe
Return

<+F3::
   Send {Volume_Mute}
Return

<+F4::
   IfWinExist ahk_exe Cura.exe
	winactivate ahk_exe Cura.exe
   else
        run "... \Cura.exe"
   WinWait ahk_exe Cura.exe
   WinActivate ahk_exe Cura.exe
   WinWaitActive ahk_exe Cura.exe
Return

<+F5::
   run explorer.exe path\to\folder\toOpen
Return

<+F6::
   Send {Volume_Up}
Return

<+F7::	
   IfWinExist ahk_exe calc.exe
	winactivate ahk_exe calc.exe
   else
        run calc.exe
   WinWait ahk_exe calc.exe
   WinActivate ahk_exe calc.exe
   WinWaitActive ahk_exe calc.exe
Return

<+F8::
   IfWinExist ahk_exe notepad++.exe
	winactivate ahk_exe notepad++
   else
        run notepad++
   WinWait ahk_exe notepad++.exe
   WinActivate ahk_exe notepad++.exe
   WinWaitActive ahk_exe notepad++.exe
Return

<+F9::
   Send {Volume_Down}
Return


>+F1::
	WinMinimize, A
Return	
	
>+F2::
	WinMaximize, A
Return	
	
>+F3::
	
Return	
	
>+F4::
	LeftHalf()
Return	
	
>+F5::
	Middle()
Return	
	
>+F6::
	RightHalf()
Return	
	
>+F7::
	LeftThird()
Return	
	
>+F8::
	MiddleThird()
Return	
	
>+F9::
	RightThird()
Return


