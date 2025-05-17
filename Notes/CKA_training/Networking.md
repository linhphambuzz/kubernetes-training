
## Switching 
![](../../img/Pasted%20image%2020250516165724.png)
- Each host has `eth0` as interface to connect to the switch 
- `ip link` : to see interfaces on the host. 
- `ip addr add` is used to add the ip adresses range of the switch to the host, used to add an IP address to a network interface (i.e: `eth0`)
- After this, A and B can talk to each other thru the switch 
- Switch can only enable communication within a network

## Routing 
- How does system in one network connected to another network? 
- Help connected 2 networks together: it assigns 2 separate ip addresses(i.e.: 192.168.1.1 and 192.168.2.1) for each network that it help connecting together. 

## Gateway 
![](../../img/Pasted%20image%2020250517110200.png)
- How does `B` know about `C` to send a packet to it? 
- Gateway: door to the world to the network
- To see the existing routing algorithm on a host: `route` cmd --> display kernel's routing table
- To configure a gateway on system B: `ip route add 192.168.2.0/24 via 192.168.1.1`
- To configure a gateway on system C: `ip route add 192.168.1.0/24 via 192.168.2.1`

