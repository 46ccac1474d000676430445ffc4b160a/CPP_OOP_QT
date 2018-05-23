#/bin/bash

git add '*.cbp'
git add '*.h'
git add '*.hpp'
git add '*.cpp'
git add '*.pro'
git add '*.zip'
git add '*.doc'
git add '*.docx'
git add 'commit.sh'

git commit -m "Update "$(date +"%y-%m-%d-%T")

git remote add origin https://github.com/46ccac1474d000676430445ffc4b160a/CPP_OOP_QT.git

echo '46ccac1474d000676430445ffc4b160a'

git push -u origin master