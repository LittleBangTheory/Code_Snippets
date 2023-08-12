#!/bin/sh

# Script used to identify every up host in a network and launch a complete scan for each host

# Parameters : $1 = Network $2 = Subnet

# Check if the number of parameters is correct
if [ $# -ne 2 ]
then
    echo "Usage: $0 <network> <subnet>"
    exit 1
fi

# Check if the scripts as been launched as root or as sudo
if [ $(id -u) -ne 0 ]
then
    echo "You must be root or use sudo to run this script"
    exit 1
fi

# Get the network part of the IP address
network_address=$(echo $1 | cut -d "." -f 1-3)

# If scan.txt or ip.txt already exist, delete them
if [ -f scan.txt ]
then
    rm scan.txt
fi

if [ -f ip.txt ]
then
    rm ip.txt
fi

# launch nmap -sn $1/$2 and store the results in a file
echo "[+] Starting ping sweep scan"
nmap -sn $1/$2 > scan.txt
echo "[+] Scan completed\r\n\r\n"

# Parse the file to get the IP addresses
echo "[+] Parsing the results"
cat scan.txt | grep -oE "\b([0-9]{1,3}\.){3}[0-9]{1,3}\b" > ip.txt
echo "[+] Parsing completed, $(wc -l ip.txt | cut -d' ' -f1) IPs identified :\r\n"

# Display the IP addresses
while read ip
do
    echo "\t$ip"
done < ip.txt
echo "\r\n\r\n"

# Launch a complete scan for each IP address and store the results in a file for each IP address
echo "[+] Starting thorough scan"
# If the directory $1 doesn't exist, create it
if [ ! -d "$1" ]
then
    mkdir $1
fi

# Get the number of IP addresses
nb_ip=$(wc -l ip.txt | cut -d ' ' -f1)

# For each IP address, launch a complete scan and store the results in a file
while read ip
do
    echo "\t[+] Scanning $ip"
    nmap -sV -O $ip > ./$1/$ip.txt

    # Get current percentage using nb_ip and the number of files in ip_files/
    percentage=$((100 * $(ls $1/*.txt | wc -l) / $nb_ip))
    echo "\t[+] Scan completed, $percentage% done\r\n";
done < ip.txt
echo "[+] Thorough scan completed\r\n\r\n"

# Delete the temporary files
echo "[+] Deleting temporary files"
rm scan.txt
rm ip.txt
echo "[+] Temporary files deleted"

# End of the script