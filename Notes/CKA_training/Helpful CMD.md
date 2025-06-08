
- `ip link` : list and modify interfaces on host 
- `ip link set dev <interface> up` :  to bring up a specific network interface
-  `ip link del <interface>` : delete connections from interface-interface
- `ip addr`: see ip addresses assigned to interfaces
- `ip addr add 192.168.1.10/24 dev eth0` : set ip addr on the interfaces
>[!Note] These cmd above won't persist unless set in /etc/sysctl.conf

- `ip route` or `route`: to view routing table  
- `ip route add 192.168.1.9/24 via 192.168.2.1` : add to routing table  
- `cat /proc/sys/net/ipv4/ip_forward`: is packet forwarding enable on the host? 
- `ps aux`: list processes
- `netstat`: cmd for network namespace 
- `openssl genrsa -out ca.key 2048` : generate key 
- `openssl req -new -key ca.key -subj "CN=KUBERNETES-CA" -out ca.csr `:  CSR 
- `openssl x509 -req -in ca.csr -signkey ca.key -out ca.crt`: sign CERT
- `cat user.csr | base64 | tr -d '\n'`