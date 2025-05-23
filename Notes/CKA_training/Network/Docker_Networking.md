## Type of docker network
### None 
```
	docker run --network none nginx
```
- Container doesn't connect to any network
- It can't reach outside world and vice versa

### Host
- Container's network is attached to host 
- There's no network isolation between the host and the container 
- Container starts at port 80 --> available at port 80 of host
- If there's another container of host network starts on port 80-> won't work 
![](../../../img/Pasted%20image%2020250522211748.png)

### Bridge 
- Isolated network within the host, by default with ip `172.17.0.0`
- Each container connects to this gets an internal private ip connects to this bridge
- The interface for this bridge network is `docker0` , created by `ip link add docker0 type bridge`
![](../../../img/Pasted%20image%2020250522212621.png)
- When containers are created, network ns is created 
- `ip netns`: to show the id of the container's network namespace
- on host: `ip link` show an interface assigned to the bridge network 
- in the container: `ip link` shows another interface
- These 2 interfaces are connected in pair


![](../../../img/Pasted%20image%2020250522213654.png)

## Port Forwarding 

![](../../../img/Pasted%20image%2020250522214302.png)

- Only host can access `172.17.0.3:80` because it's isolated
- For users to use access the app runs by the container: `-p 8080:80` -> map 8080 of host to 80 of container
- Behind the scene, docker uses NAT rule to support port fowarding
![](../../../img/Pasted%20image%2020250522221549.png)

- To list rule: `iptable -nvL -t nat`