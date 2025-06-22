
- "All Allow" rule for pods and services within the cluster
- Network Policy is an object in k8s : can be linked to one or more pods and define rules within it
- ![](../../../img/Pasted%20image%2020250614120815.png)
- policyTypes specifies whether ingress or egress traffic is affected
- When considering policyTypes, always see where it originates from. For instance, if an API wanted to make req to a DB port 3306, we want to create an ingress rule for DB

## Example 
```bash
apiVersion: networking.k8s.io/v1
kind: NetworkPolicy
metadata:
  name: test-network-policy
  namespace: default
spec:
  podSelector:   <----- policy for this pod 
    matchLabels:
      role: db
  policyTypes:  <-- specify ingress or egress here 
  - Ingress
  - Egress
  ingress:  <----- key defined for ingress rules
  - from:
    - ipBlock:
        cidr: 172.17.0.0/16
        except:
        - 172.17.1.0/24
    - namespaceSelector:     <---- from what ns do you allow the ingress to?
        matchLabels:
          project: myproject
    - podSelector:           <---- from what pod do you allow the ingress to?
        matchLabels:
          role: frontend
    ports:
    - protocol: TCP  <---- port allowed for the ingress 
      port: 6379
  egress:
  - to:
    - ipBlock:
        cidr: 10.0.0.0/24
    ports:
    - protocol: TCP
      port: 5978  <--- port to which traffic is sent to


```


>[!Important] If `namespaceSelector` and `podSelector` fall under the same list, the rule select pods under specified rule within the namespace under specified rules. 