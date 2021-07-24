## 一、Git基本创建提交

### 1、首先在需要进行仓库管理的文件夹下初始化本地仓库。

- git init

### 2、对于修改的文件，需要经过两步才会被提交到仓库，首先是将本地修改文件提交到暂存区。

- git add filename
- git add -A 表示把所有的文件都加入暂存区。

### 3、然后将暂存区的文件提交到仓库。

- git commit -m "备注"

### 4、然后提交到远程仓库。如果是新的文件夹，需要在github端新建一个仓库。

- git remote add origin git@github.com:zadwin/LeetCode.git 将远端的仓库和本文仓库进行关联。
- git branch -M main
- git push -u origin main
- git push

`备注`：可以通过 git status 查看当前本地仓库的提交情况、通过 git log 查看提交记录。
