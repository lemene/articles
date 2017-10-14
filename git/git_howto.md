
初始化远程仓库最好使用
git init --bare
它不会生成.git目录，而是把.git目录的内容（有不同）生成到当前目录，避免在此直接工作。

git init接收提交需要设置
git config receive.denyCurrentBranch ignore



git reset --hard


