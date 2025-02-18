#!/usr/bin/python3
import random
import sys
from time import sleep
import datetime

for i in range(10000):
    sleep(random.random())
    ip = "{:d}.{:d}.{:d}.{:d}".format(
        random.randint(1, 255),
        random.randint(1, 255),
        random.randint(1, 255),
        random.randint(1, 255)
    )
    status = random.choice([200, 301, 400, 401, 403, 404, 405, 500])
    size = random.randint(1, 1024)

    log_line = f"{ip} - [{datetime.datetime.now()}] \"GET /projects/260 HTTP/1.1\" {status} {size}\n"
    sys.stdout.write(log_line)
    sys.stdout.flush()
