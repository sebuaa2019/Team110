import requests
import re
import time



while(1):
    time.sleep(1)
    url = "http://114.115.255.141:8001/status/"
    header = {
        "Cookie": "csrftoken=ewmmNLpczV1r8D6dTrrf5kWUTdOFGdecVfGsc5RD6XzC0XbrBc015mnFSstWBM8M; sessionid=fixf9j2cx3bb52k68hona6zlja2oadxy"
    }
    # cookie 需要自己查看自己登录信息
    response = requests.get(url, headers=header)
    response.encoding = 'utf-8'
    html = response.text
    status = re.findall(r'value="系统状态：关" (.*?)>系统状态：关', html)
    print(status)
    f = open(r"C:\Users\周萌\Desktop\share\a.out", "w")
    # 共享文件位置
    if status[0] == "checked":
        f.write("close")
    else:
        f.write("open")
    f.close()
