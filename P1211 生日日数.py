#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
# P1211 生日日数

import datetime

data = list(map(int, input().strip().split(' ')))
date = datetime.date(year=data[0], month=data[1], day=data[2])
date += datetime.timedelta(days=10000)
print(date.strftime('%Y-%-m-%-d'))

