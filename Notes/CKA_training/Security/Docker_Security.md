## Image 

- Pattern: `registry/user_acount/image`

## Private Repository 
- Login 
- Use `imagePullSecrets` under pod's `spec`

## Docker Security 
- Process isolation: host can list processes running on host and within the container
- The container is in its own namespace 
- By default, docker runs as root
- If specified `--user=1000` , docker will run as user-id 1000
## Linux Capabilities 
- List at: `/usr/include/linux/capability.h`
![](../../../img/Pasted%20image%2020250612155036.png)
- By default, docker runs container with a limited set of capabilities
- To add capabilities:
```bash
	docker run --cap-add MAC_ADMIN ubuntu
```
- To drop capabilities:
```bash
	docker run --cap-drop KILL ubuntu
```
- To run with all privilledges: 
```bash 
	docker run ---privilleged ubuntu
```