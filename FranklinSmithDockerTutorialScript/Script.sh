#!/bin/bash
echo " "
echo "Franklin Smith"
echo " "
echo "Welcome to the Docker Automation Script, which automates dev ops.	
This script will complete the following: 
	Set up docker environment
	Build image and runs as one container
	Scale app to run multiple containers
	Distribute your app across a cluster
	Stack services by adding a backend database
	Deploy your app to production
"

echo " "
echo "Docker Tutorial Installation Script Part One: Environment"
echo "Preparing The Docker Environment"
echo "Your Docker Version is:"
docker --version
docker run hello-world
docker image ls
echo "End of Part 1 Preparing Docker Environment"




echo " "
echo "Docker Tutorial Installation Script Part Two: Containers"
echo "Getting Started With Containers"
echo " "
echo "Verifying that the Dockerfile included in tutorial exists and correctly contains the following contents"
echo " "
cat Dockerfile
echo " "
echo "Verifying that the requirements.txt file in tutorial exists and correctly contains the following contents"
echo " "
cat requirements.txt
echo " "
echo "Verifying that the app.py file in tutorial exists and correctly contains the following contents"
echo " "
cat app.py
echo " "
echo "Installing flask and redis libraries for python"
echo " "
pip install --user -r requirements.txt
echo " "
echo "Building the app"
echo " "
docker build --tag=friendlyhello .
echo " "
docker image ls
echo " "
echo "opening http://localhost:4000/ and refresh browser. Each refresh should result in a get request output in the terminal"
echo " "
open -a "Google Chrome" http://localhost:4000/
echo " "
echo "Run the app, mapping your machine’s port 4000 to the container’s published port 80"
echo " "
docker run -p 4000:80 friendlyhello
echo " "
docker login
echo " "
read -p "Enter your Docker username: " username
echo " "
#read -p "Enter a repository name in which to push your container: " repo
echo " Running docker tag image with your username, repository, and tag names so that the image uploads to your desired destination. "
echo " " 
docker tag friendlyhello $username/friendlyhello:latest
echo " "
#read -p "Enter a name for your App!: " appName
echo " "
docker image ls
echo " "
echo "Upload your tagged image to the repository"
echo " "
docker push $username/friendlyhello:latest
echo " "
echo "opening http://localhost:4001/ and refresh browser. Each refresh should result in a get request output in the terminal"
echo " "
open -a "Google Chrome" http://localhost:4001/
echo " "
echo "End of Part Two Getting started with containers"
echo "Built a python app using a python runtime on your local machine"
echo " "
echo "Pulling and runing the image from the remote repository "
echo " "
docker run -p 4001:80 $username/friendlyhello:latest
echo " "





echo "Docker Tutorial Installation Script Part Three: Services"
echo "Getting Started With Services"
echo " "
echo " "
docker swarm leave --force
echo " "
docker swarm init
echo " "
#read -p "Enter a name for your App!: " appName
#echo " "
echo "Running your app called friendlyhello"
echo " "
docker stack deploy -c docker-compose.yml friendlyhello #getstartedlab #$appName
echo " "
echo "Getting the service ID for the one service in our application:"
docker service ls
echo " "
docker stack services friendlyhello #getstartedlab
echo " "
echo "Listing the tasks for your service"
docker service ps friendlyhello_web #getstartedlab_web #$appName
echo " "
echo "Listing all of the containers on your system"
docker container ls -q
echo " "
#open http://localhost:4000
echo " "
echo "Viewing all tasks of your stack"
echo " "
docker stack ps friendlyhello #getstartedlab #$appName
echo " " 
echo "Scaling up the app"
echo " "
docker stack deploy -c docker-compose.yml friendlyhello #getstartedlab #$appName
echo " "
echo "This Part of the program will take down the app and the swarm"
echo " "
echo "Taking down the app"
echo " "
docker stack rm friendlyhello #getstartedlab #$appName
echo " "
echo "Taking down the swarm"
echo " "
docker swarm leave --force
echo " "
docker tag friendlyhello $username/friendlyhello:latest
echo " "
docker push $username/friendlyhello:latest
echo " " 
echo "End of part 3 getting started with services"
echo "The above steps allow the user to create and scale your app with docker."
echo "This is closer to learning how to run the containers in production."
echo " "







echo "Docker Tutorial Installation Script Part Four: Swarms"
echo "Getting Started With Swarms"
echo " "
echo "Enabling swarm mode and making local machine current manager"
#echo " "
#docker swarm init
echo " "
echo "Creating VM's using docker-machine"
echo " "
#read -p "Enter a unique name for your first virtual machine: " VM1
#read -p "Enter a unique name for your second virtual machine " VM2
docker-machine create --driver virtualbox myvm1
echo " "
docker-machine create --driver virtualbox myvm2
echo " "
echo "Listing VM's and their IP addresses"
echo " "
docker-machine ls
echo " "
read -p "Enter the entire IP address of myvm1: " IPVM1
echo " "
echo "Instructing VM1 to become swarm manager with docker swarm init"
echo " "
a='docker swarm init --advertise-addr '
b=$IPVM1
c="$a$b"
docker-machine ssh myvm1 $c
echo " "
echo " "
read -p "Enter the above TOKEN into the terminal: " TOKENVAL
echo " "
echo "Creating your first swarm"
echo " "
docker-machine ls
echo " "
read -p "Enter ONLY the first 11 numbers of the IP address of VM1: " SHORTERIP
echo " "
read -p "Enter ONLY the first 11 numbers of the IP address of VM2: " SHORTERIP2
#docker swarm join --token $TOKENVAL $SHORTERIP:2377
docker-machine ssh myvm2 docker swarm join --token $TOKENVAL $SHORTERIP:2377
echo " "
#docker-machine ssh myvm2 docker swarm join --token $TOKENVAL $IPVM1 #:2377
#docker-machine ssh myvm2 docker swarm join \ --token <token> \ <ip>:2377
#echo " "
#docker swarm join --token $TOKENVAL $IPVM1 #:2377
#echo " "
#echo "Viewing your nodes in the swarm"
#docker swarm init
#echo " "
#docker swarm join
echo " "
docker-machine ssh myvm1 docker node ls
echo " "
echo "Configuring shell to talk to VM"
echo " "
docker-machine env myvm1
echo " "
eval $(docker-machine env myvm1)
echo " "
echo "Verify that your first virtual machine is active, it should have an asterisk in the active column."
echo " "
docker-machine ls
echo " "
echo "Deploying the app on a swarm cluster"
echo " "
docker stack deploy -c docker-compose.yml friendlyhello #$appName
echo " "
#open http://$IPVM1:4000
echo " "

docker stack ps friendlyhello #$appName
echo " "
#echo "Looking at the cluster from IP addresses of the vms"
#read -p "Enter the IP address of your first virtual machine: " FIRSTCHROMEOPENER
#echo "Tearing down the swarm stack"
#echo " "
#docker stack rm $appName
#echo " "
#echo "Unsetting the docker-machine environment variables in current shell"
#echo " "
#eval $(docker-machine env -u)
#echo " "
echo "Checking statuses of machines"
echo " "
eval $(docker-machine env myvm1)
echo " "
echo "Listing machines and making sure you are connected to vm1, should have asterisk next to it"
echo " "
docker-machine ls
echo "Deploying the app on the swarm manager"
echo " "
docker stack deploy -c docker-compose.yml friendlyhello
echo " "
#docker-machine ls
echo " "
echo "Checking docker ps stack"
echo " "
docker stack ps friendlyhello #$appName
echo " "
docker-machine ls
echo " "
open -a "Google Chrome" http://$SHORTERIP:4000/
echo " "
open -a "Google Chrome" http://$SHORTERIP2:4000/
#docker-machine rm myvm1
#docker-machine rm myvm2
echo " "
echo "Now you have successfully learned about swarms, how nodes in them can be managers or workers, created a swarm, and deployed an application on it."
echo " "
echo " "
echo "Docker Tutorial Installation Script Part Five: Stacks"
echo " "
echo "Verifying machines are set up and Running"
echo " "
docker-machine ls
echo " "
echo "Initializing Swarm"
echo " "
docker swarm init
echo " "
echo "Creating a Data directory on the manager"
echo " "
docker-machine ssh myvm1 mkdir ./data
echo " "
echo "Deploying the stack"
echo " "
docker stack deploy -c docker-compose.yml friendlyhello
echo " "
echo "Opening the webpages to both of the servers"
echo " "
echo "Switch between the two webpages and hit refresh to increment the Visit count for the servers!"
echo " "
open -a "Google Chrome" http://$SHORTERIP:4000/
echo " "
open -a "Google Chrome" http://$SHORTERIP2:4000/
echo " "
echo "Here in part 5, you reach the top of the hierarchy of distributed applications: the stack."
echo "A stack is a group of interrelated services that share dependencies, and can be orchestrated and scaled together."
echo "A single stack is capable of defining and coordinating the functionality of an entire application."
echo "Complex and or complex apps may want to use multiple stacks. "
echo " "
echo "Please Refer to installation guide document to read about part 6: Deploying your app"
echo " "
read -p "Enter "quit" when you are ready to quit the program: " EXIT
echo " "
echo "The program will remove docker swarm and VM's."
echo " "
docker stack rm friendlyhello
echo " "
docker-machine rm myvm1
echo " "
docker-machine rm myvm2
echo " "
echo "Exiting the Docker automation dev ops script."
echo " "









