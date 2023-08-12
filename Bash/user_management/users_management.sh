#!/bin/bash

#Init first UID
$uid=1001

#File to put username:temp_password
echo "username:temp_password" > temp_password.txt
for line in $(cat noms.csv); do
        #Get the three fields
        username=$(echo $line | cut -d';' -f1)
        date=$(echo $line | cut -d';' -f2)
        group=$(echo $line | cut -d';' -f3)
        echo "username = $username"
        echo "date = $date"
        echo "group = $group"

        #Create the user with the default uid and gid
        adduser $username --uid $uid --gid $uid

        #Create a temporary password and give it to chpasswd
        password=$(pwgen -y 15 1)
        echo "$username:$password" | chpasswd 
        echo "$username:$password" >> temp_password.txt
        #set the last change date to 0 epoch time to force change at first login
        chage -d 0 $username

        #If the group field isn't empty, add the user to it
        if [-n "$group"];then
                usermod -a -G $group $username
        fi

        #If the date field isn't empty, add an expiration date to the password
        # -M 60 - the password is valid 60 days
        # -W 10 - the user is warned 10 days in advance
        # -I 30 - the account is deleted after 30 days of inactivity
        if [-n "$date"];then
                chage -M 60 -W 10 -I 30 $username
        else
                #otherwise it is a permanent account, password is valid 120 days, and user is warned 20 days before
                chage -M 120 -W 20 -I 30 $username
        fi

        #get the next uid
        uid=$(($uid+1))
done