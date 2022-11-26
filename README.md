# instant_message_system

## Installation steps

### Theses steps are proven to work on local machine/virtual machine/same network computers(Mac/Windows)

1. login to server machine (Macbook Pro)

2. clone repo to home directory or similar

`$ cd instant_message_system`

`$ gcc server.c -o server`

`$ ./server`

3. login to client machine (Windows PC)

4. clone repo to home directory or similar

`$ cd instant_message_system`

5. WARNING: If the client and server are not on the same network than use the private IP of the Macbook Pro (75.245.171.86), this can be done by uncommenting/commenting lines 54/56 on the client.c file

`$ gcc client.c -o client`

`$ ./client`

6. client initiates 'talking' to server

7. server can respond with message

8. steps 7 and 8 continue until the server (Macbook Pro) send 'exit'
