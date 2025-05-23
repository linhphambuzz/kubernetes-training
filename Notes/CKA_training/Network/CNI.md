- Set of standard that defines how programs should be developed to solve networking challenges in cntainer runtime environment. 
- Bridge network is a pluggin for CNI 
- So long as these following set of rule are followed, cntainer runtimes and CNI works on harmony
![](../../../img/Pasted%20image%2020250522220736.png)

- Docker does't support CNI, it has its own thing (i.e:CNM)
- In Kubernetes: docker container is created with `none` network, then the container is added to the bridge network later on by the configured CNI plugins. 
![](../../../img/Pasted%20image%2020250522221251.png)