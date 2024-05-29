#!/usr/bin/env python3
#
# Reads words from standard in and finds conflicts when in dænsk.

import sys
import re
from collections import defaultdict

def to_dænsk(s):
    return re.sub(r'a+', 'å', re.sub(r'[ou]+', 'ø', re.sub(r'[eiy]+', 'æ', s.lower())))

words = defaultdict(list)

for line in sys.stdin:
    dansk = line.rstrip()
    dænsk = to_dænsk(dansk)
    words[dænsk].append(dansk)

n_ambigious = 0
for dænsk, dansks in words.items():
    if len(dansks) > 1:
        n_ambigious += 1
        dansks = ', '.join(dansks)
        print(f'{dænsk}: {dansks}')

print('-' * 50)
print('N ambigious', n_ambigious)
print('N total', len(words))
print('Percentage ambigious', 100 * n_ambigious / len(words), '%')
