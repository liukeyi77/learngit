//指令

//创建版本库

git init//把git变成可管理仓库
git add readme.txt//把文件添加到仓库
git commit -m "wrote a readme file"//把文件提交到仓库
//add支持同时添加多个，然后commit

//版本退回
git log//查看历史记录
	 git log --pretty=oneline
git reset --hard HEAD^//退回上一版本
git reset --hard 3628164//退回有commit id的版本
git reflog //记录指令

//第一次修改 -> git add -> 第二次修改 -> git add -> git commit

rm test.txt
git rm test.txt//从版本库中删除该文件，那就用命令git rm删掉，并且git commit

git checkout -- readme.txt//可以很轻松地把误删的文件恢复到最新版本：
/*
命令git checkout -- readme.txt意思就是，把readme.txt文件在工作区的修改全部撤销，这里有两种情况：
一种是readme.txt自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；
一种是readme.txt已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。
*/
git push origin master//把本地master分支的最新修改推送至GitHub，现在，你就拥有了真正的分布式版本库！
/*
要关联一个远程库，使用命令
git remote add origin git@server-name:path/repo-name.git
*/
