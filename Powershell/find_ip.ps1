# Define IP range
$ipRange = "10.64.1."

# Define start and end IP address
$start = 1
$end = 254

# Get the current computer IP address
$computerIP = (Get-NetIPAddress -AddressFamily IPv4 | Where-Object {$_.InterfaceAlias -eq "Ethernet"}).IPAddress

# Loop through the IP range
for ($i = $start; $i -le $end; $i++) {
	# Define IP for this iteration
	$ip = $ipRange + $i
	
	# Test if $ip is different from $computerIP
	if ($ip -ne $computerIP) {
    		Write-Host "$ip is different from the computer IP address"
		
		# Test if $ip is available
		if (!(Test-Connection -ComputerName $ip -Count 1 -Quiet)) {
        		Write-Host "The first available IP address is $ip"
        		break
    		}
	}
}

# Set the IP address
$wmi = Get-WmiObject -Class Win32_NetworkAdapterConfiguration -Filter "IPEnabled = 'True'"
$wmi.EnableStatic($ip, "255.255.255.0")