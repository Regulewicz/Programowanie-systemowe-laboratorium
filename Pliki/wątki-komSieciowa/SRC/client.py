import socket

while True:
    text = input("Wpisz tekst: ")
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect(("127.0.0.1", 8080))
        s.sendall(text.encode())
        if text == "EXIT":
            break
        print(s.recv(2048).decode(), end="\n")