#!/bin/bash
arc=$(uname -a)
pcpu=$(grep "physical id" /proc/cpuinfo | wc -l)
vcpu=$(grep "processor" /proc/cpuinfo | wc -l)
ram=$(	free -m | grep Mem | awk '{printf("%s/%sMB (%.2f%%)", $3, $2, ($3/$2)*100)}')
disk=$(df -h --total | grep total | awk '{printf("%.1f/%.fGb (%s)", $3, $2, $5)}')
cpul=$(top -bn1 | grep Cpu | awk '{printf("%.1f%%", $2 + $4)}')
lboot=$(uptime -s | awk '{printf("%s %s\n", $1, substr($2, 1, length($2) - 3))}')
lvm=$(lsblk | grep lvm | wc -l | awk '{if ($1){printf("yes"); exit;} else print "no"}')
#install netstat
ntcp=$(netstat -an | grep ESTABLISHED | wc -l)
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(cat /sys/class/net/enp0s3/address)
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $ram
	#Disk Usage: $disk
	#CPU load: $cpul
	#Last boot: $lboot
	#LVM use: $lvm
	#Connexions TCP: $ntcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $sudo cmd"