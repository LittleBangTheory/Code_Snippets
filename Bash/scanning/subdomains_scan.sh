#!/bin/bash

url=$1

if [ "$#" -ne 1 ]; then
        echo "As root : ./run.sh <domain>"
else
        if [ ! -d "$url" ];then
                echo "[+] Creating $url/ folder..."
                mkdir $url
        fi
        if [ ! -d "$url/recon" ];then
                mkdir $url/recon
                echo "[+] Creating $url/recon/ folder..."
        fi

        echo "[+] Harvesting subdomains with assetfinder..."
        assetfinder $url >> $url/recon/assets.txt
        cat $url/recon/assets.txt | grep $1 >> $url/recon/final.txt
        rm $url/recon/assets.txt
        echo "[+] Results are in $url/recon/final.txt"
fi