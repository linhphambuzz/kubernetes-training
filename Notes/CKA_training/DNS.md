

## Small setup, no centralized DNS server 
- `cat >> /etc/host` is source of truth for small environment
![](../../img/Pasted%20image%2020250520143641.png) 

## Centralized DNS server 

- `cat /etc/resolve.conf`  -> `dns-name-server 192.168.1.100` : the dns server is at .1.100 ip
- If there's two alias for same host: local host is effective
- `cat /etc/nsswitch.conf` 

```bash
	# /etc/nsswitch.conf
	#
	# Example configuration of GNU Name Service Switch functionality.
	# If you have the `glibc-doc-reference' and `info' packages installed, try:
	# `info libc "Name Service Switch"' for information about this file.
	
	passwd:         files systemd
	group:          files systemd
	shadow:         files
	gshadow:        files
	
	hosts:          files mdns4_minimal [NOTFOUND=return] dns  <-- l to r order
	networks:       files
	
	protocols:      db files
	services:       db files
	ethers:         db files
	rpc:            db files
	
	netgroup:       nis

```

- `/etc/resolve.conf` can be used to add server name that host doesn't know about. But if the server is a popular one, entry should be added to centralized DNS server

## Core DNS 
We are given a server dedicated as the DNS server, and a set of Ips to configure as entries in the server. There are many DNS server solutions out there, we will focus on a particular one – CoreDNS

### Install 

![](../../img/Pasted%20image%2020250521125153.png)

### Set up
- First we put all of the entries into the DNS servers `/etc/hosts` file
- And then we configure CoreDNS to use that file. CoreDNS loads it’s configuration from a file named Corefile. Here is a simple configuration that instructs CoreDNS to fetch the IP to hostname mappings from the file /etc/hosts. When the DNS server is run, it now picks the Ips and names from the /etc/hosts file on the server

![](../../img/Pasted%20image%2020250521125532.png)

