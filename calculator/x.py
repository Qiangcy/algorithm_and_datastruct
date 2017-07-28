# from http import cookies
import sys
import datetime
import os
import requests
cookie = {'85porn': 'uk35k8pas9kor4glpdovad6ii3'}
# 85porn=7ijn7mar13e7cm2r03eltrao52; _ga=GA1.2.1282453290.1494033161; _gid=GA1.2.294872771.1499446038; remember=a:3:{s:8:"username";s:7:"YongHao";s:8:"password";s:32:"75b0390fe958d5c66cf161ca246ea482";s:5:"check";s:40:"a48ca1f9b65995ef175f39d728c1ef61d117c9ea";}

url = "https://www.85porn.com/download.php?id="
start_id = int(sys.argv[1])
numbers = int(sys.argv[2])
pdir = os.path.join("/tmp", "p_dir", datetime.date.today().isoformat())

if not os.path.exists(pdir):
    os.makedirs(pdir)

for pid in range(start_id, start_id+numbers):
    download_url = url + str(pid)
    print(download_url)
    filename = os.path.join(pdir, str(pid)+".mp4")
    print("%s is downloading now ......\n\n" % filename)
    r = requests.get(download_url, timeout=2000000, cookies=cookie)
    size = len(r.content)
    print(size)
    if size >= 0 and size < 2*1024*1024:
        print("skip")
        continue
    with open(filename, "wb") as code:
        for chunk in r.iter_content(chunk_size=255):
            if chunk: # filter out keep-alive new chunks
                code.write(chunk)
        # code.write(f.read())
