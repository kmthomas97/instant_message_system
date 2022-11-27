# instant_message_system

## Configure Environment/WSL (Windows Subsystem for Linux) LINK FOR MORE INFO: https://learn.microsoft.com/en-us/windows/wsl/install

1. In Powershell/Command Prompt Administrator mode enter

`$ wsl --install`

2. Go to https://ubuntu.com/wsl to install Ubuntu on your new WSL

3. Follow installation steps and setup a username and password

4. You should see a prompt once finished enter

`$ sudo apt update && sudo apt upgrade`

5. type y or yes for any options

6. Install gcc and git

`$ sudo apt install gcc && sudo apt install git`

7. Congrats, if everything went well you should be done setting up your environment!

## Repository setup steps

### Theses steps are proven to work on local machine/virtual machine/same network computers(Mac/Windows)

### Server Steps

1. login to server machine (Macbook Pro)

2. clone repo to home directory or similar

`$ cd instant_message_system`

`$ gcc server.c -o server`

`$ ./server`

### Client Steps

1. login to client machine (Windows PC)

2. Open Ubuntu on Windows (e.g. WSL) 

3. clone repo to home directory or similar

`$ cd instant_message_system`

4. WARNING: If the client and server are not on the same network than use the private IP of the Macbook Pro (75.245.171.86), this can be done by uncommenting/commenting lines 54/56 on the client.c file

`$ gcc client.c -o client`

`$ ./client`

### Running Steps

6. client initiates 'talking' to server

7. server can respond with message

8. steps 7 and 8 continue until the server (Macbook Pro) send 'exit'
