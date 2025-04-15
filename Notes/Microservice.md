## Steps
1. Deploy PODs
2. Create Services (Cluster IP):  redis, db
![alt text](Pasted_image_20240627090413.png)

- the source code of `app.py` and `program.cs` is set to point to `redis`
 - this clusterIP is for internal access only

![alt text](Pasted_image_20240627090800.png)


3. Create services (Nodeport): voting-app, result-app