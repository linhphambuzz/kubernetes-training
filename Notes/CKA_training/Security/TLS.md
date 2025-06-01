guarantee trust between client-server

## Encryption
### Symetric Encryption 

- Same key to encrypt and decrypt data
- key has to be exchanged between client-svr
### Asymetric Encryption 
- Uses a pair of private key  and public lock 
![](../../../img/Pasted%20image%2020250526214028.png)
- Example: using SSH server to authenticate (`id_rsa`&& `id_rsa.pub`)
1. Use ssh-keygen to generate a set of public and private key
2. The server will save the public's key (`cat ~/.ssh/authorized_keys`)	
3. On logging in the server, user specify the private key: `ssh -i id_rsa user@server1`

#### Using openssl 

```bash
openssl genrsa -out my-banj.key 1024
openssl rsa -in my-bank.key -pubout > mybank.pem
```

- User accesses the web using `https`, he gets public key from the server 
- User's browser encrypt the symmetric key using the public key provided by the server. They then send this to the server 
- The server uses the priv. key to decrypt the encrypted key sent by the user 

## Certificate Authority 
![](../../../img/Pasted%20image%2020250601155034.png)
- Self-sign: not safe, anyone can sign 
- CA: well known org that signs and validate vertificates 
### Procedure
1. Generate Certificate Signing Request (CSR)
	```bash
	openssl req -new -key my-bank.key -out -subj "/C=US/ST=CA/O=MyOrg, Inc./CN=mybank.com"
	```
2. Validate Information: CSA verify your info
3. Sign and Send Certificate  
--> certificate signed by CA that the browser trusts 

### How does the browser know that CA is valid? 

- CA themselves have set of public/private keys 
- CA uses priv. key to sign the certificate 
- CA's public key are built in to the browser 
- Sites private can host private instance of CA within your organization

## Summary 

- To encrypt message sent over the network, we use asymmetric encryption 
- Admins use public +priv keys to secure ssh connection to the server 
- The server uses a pair of key to secure https traffic. They send CSR  to a CA who uses the private key to sign the certificate. The signed certificate (CERT) is sent back to the server
- When the user tries to access the web server, CERT (with public key) first gets sent from the server. The user then uses the CERT to retrieve the public key sent from the server ==> A symmetric key is then generated to be used from then on.
- The symmetric key (encrypted with server's public key) is sent back to the server. The server uses its priv key to decrypt the message to get the symmetric key. The symmetric key is used for communication going forwards
- After trust from client is establish, clients can use username + password for authentications 
- Client Certificates involves getting CSR to obtain CERT which would be sent to the server to tell server that the clients are trustworthy
- Generally, web servers use TLS certificate to help clients avoid manually managing client certificates by themselves
![](../../../img/Pasted%20image%2020250601165535.png)