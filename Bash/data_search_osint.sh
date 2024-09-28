#!/bin/bash
## Updated: January 14, 2024
## Full usage details are available in the book: https://inteltechniques.com/book1a.html
## Please report any issues to errors@inteltechniques.com
## Copyright 2023 Michael Bazzell
## These instructions are provided 'as is' without warranty of any kind
## In no event shall the copyright holder be liable for any claim, damages or other liability
## Full license information and restrictions at https://inteltechniques.com/osintbook10/license.txt

opt1="COMB Email Search" 
opt2="COMB Term Search" 
opt3="Combos Search"
opt4="Databases Search-Filename" 
opt5="Databases Search-Content" 
opt6="Databases Search-Filename & Content"
opt7="Hashes Search-Filename"
opt8="Hashes Search-Content"
opt9="Hashes Search-Filename & Content"
opt10="International Search" 
opt11="Logs Search" 
opt12="Logs Daily Sort"
opt13="Logs Weekly Merge"
opt14="People Search-Filename" 
opt15="People Search-Content" 
opt16="People Search-Filename & Content" 
opt17="Ransomware Search"
opt18="Voter Search-Filename" 
opt19="Voter Search-Content" 
opt20="Voter Search-Filename & Content" 
opt21="Whois Search"
opt22="All Filename Search"
opt23="All Content Search"
opt24="All Filename & Content Search"

menu=$(zenity --list --title "Data Tool" --radiolist --column "" --column "" TRUE "$opt1" FALSE "$opt2" FALSE "$opt3" FALSE "$opt4" FALSE "$opt5" FALSE "$opt6" FALSE "$opt7" FALSE "$opt8" FALSE "$opt9" FALSE "$opt10" FALSE "$opt11" FALSE "$opt12" FALSE "$opt13" FALSE "$opt14" FALSE "$opt15" FALSE "$opt16" FALSE "$opt17" FALSE "$opt18" FALSE "$opt19" FALSE "$opt20" FALSE "$opt21" FALSE "$opt22" FALSE "$opt23" FALSE "$opt24" --height=700 --width=300)

case $menu in

$opt1 )
zenity --info --text="This option queries the COMB database for full or partial email addresses. Click "OK" to begin" --title="COMB Email Search"
data=$(zenity --entry --title "COMB Email Search" --text "Enter Target Email")
cd /Volumes/DATA/COMB
bash ./query.sh $data
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt2 )
zenity --info --text="This option queries the COMB database for any term. Click "OK" to begin" --title="COMB Term Search"
data=$(zenity --entry --title "COMB Term Search" --text "Enter Target Data")
cd /Volumes/DATA/COMB
rg -aFiN $data
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt3 )
zenity --info --text="This option queries combo files for any term. Click "OK" to begin" --title="COMB Term Search"
data=$(zenity --entry --title "Combos Search" --text "Enter Target Data")
cd /Volumes/DATA/Combos
rg -aFiN $data
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt4 )
zenity --info --text="This option queries all file names in the Databases folder. It is used to identify the exact file name to be searched next. Click "OK" to begin" --title="Databases Search-Filename"
data=$(zenity --entry --title "Databases Search-Filename" --text "Enter Partial Filename")
cd /Volumes/DATA/Databases
find . | grep -i $data
echo
echo "Select and copy any file path and press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt5 )
zenity --info --text="This option queries all Databases for any term. Click "OK" to begin" --title="Databases Search-Content"
data=$(zenity --entry --title "Databases Search-Content" --text "Enter Target Data")
cd /Volumes/DATA/Databases
rg -aFiN $data
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt6 )
zenity --info --text="This option queries only a specific Database file for any term. Click "OK" to begin" --title="Databases Search-Filename & Content"
data1=$(zenity --entry --title "Databases Search-Filename & Content" --text "Enter File Path")
data2=$(zenity --entry --title "Databases Search-Filename & Content" --text "Enter Target Data")
cd /Volumes/DATA/Databases
rg -aFiN $data2 $data1
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt7 )
zenity --info --text="This option queries all file names in the Hashes folder. It is used to identify the exact file name to be searched next. Click "OK" to begin" --title="Hashes Search-Filename"
data=$(zenity --entry --title "Hashes Search-Filename" --text "Enter Partial Filename")
cd /Volumes/DATA/Hashes
find . | grep -i $data
echo
echo "Select and copy any file path and press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt8 )
zenity --info --text="This option queries all Hashes for any term. Click "OK" to begin" --title="Hashes Search-Content"
data=$(zenity --entry --title "Hashes Search-Content" --text "Enter Target Data")
cd /Volumes/DATA/Hashes
rg -aFiN $data
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt9 )
zenity --info --text="This option queries only a specific Hashes file for any term. Click "OK" to begin" --title="Hashes Search-Filename & Content"
data1=$(zenity --entry --title "Hashes Search-Filename & Content" --text "Enter File Path")
data2=$(zenity --entry --title "Hashes Search-Filename & Content" --text "Enter Target Data")
cd /Volumes/DATA/Hashes
rg -aFiN $data2 $data1
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt10 )
zenity --info --text="This option queries International files for any term. Click "OK" to begin" --title="International Term Search"
data=$(zenity --entry --title "International Search" --text "Enter Target Data")
cd /Volumes/DATA/International
rg -aFiN $data
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt11 )
zenity --info --text="This option queries Logs files for any term. Click "OK" to begin" --title="Logs Search"
data=$(zenity --entry --title "Logs Search" --text "Enter Target Data")
cd /Volumes/DATA/Logs
rg -aFiN $data
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt12 )
zenity --info --text="This option combines all log files within the Telegram download folder and sorts for unique entries. Click "OK" to begin" --title="Logs Daily Sort"
timestamp=$(date +%Y-%m-%d-%H-%M)
cd ~/Downloads/Telegram\ Desktop
cat *.txt > Logs.csv
rm *.txt
mv Logs.csv Logs.txt
LC_ALL=C sort -u -b -i -f -S 80% --parallel=8 Logs.txt > Logs-Sorted-$timestamp.txt
rm Logs.txt
mv Logs-Sorted-$timestamp.txt ~/Downloads/
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt13 )
zenity --info --text="This option merges all sorted Logs files within the Downloads folder with the primary collection on the SSD. Click "OK" to begin" --title="Logs Weekly Merge"
cd ~/Downloads
LC_ALL=C sort -u -b -i -f -m Logs* /Volumes/DATA/Logs/* > Current.txt
rm Logs* /Volumes/DATA/Logs/* 
mv Current.txt /Volumes/DATA/Logs/Current.txt
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt14 )
zenity --info --text="This option queries all file names in the People folder. It is used to identify the exact file name to be searched next. Click "OK" to begin" --title="People Search-Filename"
data=$(zenity --entry --title "People Search-Filename" --text "Enter Partial Filename")
cd /Volumes/DATA/People
find . | grep -i $data
echo
echo "Select and copy any file path and press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt15 )
zenity --info --text="This option queries all People data for any term. Click "OK" to begin" --title="People Search-Content"
data=$(zenity --entry --title "People Search-Content" --text "Enter Target Data")
cd /Volumes/DATA/People
rg -aFiN $data
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt16 )
zenity --info --text="This option queries only a specific People file for any term. Click "OK" to begin" --title="People Search-Filename & Content"
data1=$(zenity --entry --title "People Search-Filename & Content" --text "Enter File Path")
data2=$(zenity --entry --title "People Search-Filename & Content" --text "Enter Target Data")
cd /Volumes/DATA/People
rg -aFiN $data2 $data1
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt17 )
zenity --info --text="This option queries all Ransomware data for any term. Click "OK" to begin" --title="Ransomware Search"
data=$(zenity --entry --title "Ransomware Search" --text "Enter Target Data")
cd /Volumes/DATA/Ransomware
rg -aFiN $data
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt18 )
zenity --info --text="This option queries all file names in the Voter folder. It is used to identify the exact file name to be searched next. Click "OK" to begin" --title="Voter Search-Filename"
data=$(zenity --entry --title "Voter Search-Filename" --text "Enter Target Data")
cd /Volumes/DATA/Voter
find . | grep -i $data
echo
echo "Select and copy any file path and press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt19 )
zenity --info --text="This option queries all Voter data for any term. Click "OK" to begin" --title="Voter Search-Content"
data=$(zenity --entry --title "Voter Search-Content" --text "Enter Target Data")
cd /Volumes/DATA/Voter
rg -aFiN $data
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt20 )
zenity --info --text="This option queries only a specific Voter file for any term. Click "OK" to begin" --title="Voter Search-Filename & Content"
data1=$(zenity --entry --title "Voter Search-Filename & Content" --text "Enter File Path")
data2=$(zenity --entry --title "Voter Search-Filename & Content" --text "Enter Target Data")
cd /Volumes/DATA/Voter
rg -aFiN $data2 $data1
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt21 )
zenity --info --text="This option queries all Whois data for any term. Click "OK" to begin" --title="Whois Search"
data=$(zenity --entry --title "Whois Search" --text "Enter Target Data")
cd /Volumes/DATA/Whois
rg -aFiN $data
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt22 )
zenity --info --text="This option queries all file names. It is used to identify the exact file name to be searched next. Click "OK" to begin" --title="All Filename Search"
data=$(zenity --entry --title "All Filename Search" --text "Enter Partial Filename")
cd /Volumes/Data/
find . | grep -i $data
echo
echo "Select and copy any file path and press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt23 )
zenity --info --text="This option queries all data for any term. Click "OK" to begin" --title="All Content Search"
data=$(zenity --entry --title "All Content Search" --text "Enter Target Data")
cd /Volumes/Data/
rg -aFiN $data
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;

$opt24 )
zenity --info --text="This option queries only a specific file for any term. Click "OK" to begin" --title="All Filename & Content Search"
data1=$(zenity --entry --title "All Filename & Content Search" --text "Enter File Path")
data2=$(zenity --entry --title "All Filename & Content Search" --text "Enter Target Data")
cd /Volumes/Data/
rg -aFiN $data2 $data1
echo
echo "Press Enter to return to menu"
read data
exec /Applications/DataTool
;;
esac
