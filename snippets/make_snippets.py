'''Make vscode snippets file'''
import os
import json

# get all .cpp file paths from directory, recursive with os.walk
dir = 'src'
files = []
for (path, dir, filenames) in os.walk(dir):
    for filename in filenames:
        ext = os.path.splitext(filename)[-1]
        if ext == '.cpp':
            files.append(os.path.join(path, filename))
files.sort()
# from files, make snippets
# file is '000_title.cpp'
snippets = {}
for file in files:
    with open(file, 'r') as f:
        now_header = False
        now_interest = False
        body = []
        body_interest = []
        for line in f:
            line = line.replace('\n', '')
            if line.startswith('/*!'):
                now_header = True
            elif line.startswith('!*/'):
                now_header = False
            elif line.startswith('//['):
                now_interest = True
            elif line.startswith('//]'):
                now_interest = False
            elif now_header:
                k, v = map(lambda x:x.strip(), line.split(':'))
                exec(f'{k} = "{v}"')
            elif now_interest:
                line = line.replace('//!', '')
                body_interest.append(line)
            else:
                line = line.replace('//!', '')
                body.append(line)
        if len(body_interest) > 0:
            body = body_interest
    snippets[title] = dict(scope='cpp', prefix=prefix, body=body, description=description)

json.dump(snippets, open('library.code-snippets', 'w', encoding='utf-8'), indent=4, ensure_ascii=False)
print('Done!')