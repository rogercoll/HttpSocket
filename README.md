# HttpSocket

Very basic Socket implementation that serves a html file on port 80.

### Usage

##### UNIX commands:
```
git clone https://github.com/rogercoll/HttpSocket.git
cd HttpSocket
gcc -o serverSocket serverSocket.c socketMng.c
./serverSocket 80
```
#### On any browser:
```
localhost:80
```
<br>

> Remember that the port for web services must be 80

<br>

> It serves the file whose name is "baidu.html" and is located in "/WEB"
