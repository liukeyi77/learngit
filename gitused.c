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

git checkout -b dev//我们创建dev分支，然后切换到dev分支
/*
与上一句等价
git branch dev
git checkout dev
*/
git branch//命令查看当前分支
git add readme.txt 
git commit -m "branch test"
git checkout master//切换回master分支

git merge dev//把dev分支的工作成果合并到master分支上
git branch -d dev//删除dev分支了

//解决冲突问题
/*
1.git checkout -b feature1
 修改readme.txt最后一行，改为：
Creating a new branch is quick AND simple.
2.在feature1分支上提交：
$ git add readme.txt 
$ git commit -m "AND simple"
3.切换到master分支：
$ git checkout master
在master分支上把readme.txt文件的最后一行改为：
Creating a new branch is quick & simple.
提交：
$ git add readme.txt 
$ git commit -m "& simple"
*/
//git merge feature1冲突了
//直接查看readme.txt的内容：
/*
我们修改如下后保存：
Creating a new branch is quick and simple.
再提交：
$ git add readme.txt 
$ git commit -m "conflict fixed"
*/
/*
用带参数的git log也可以看到分支的合并情况：
$ git log --graph --pretty=oneline --abbrev-commit
*/

//分支管理策略
/*
相比较与分支冲突
准备合并dev分支，请注意--no-ff参数，表示禁用Fast forward：
git merge --no-ff -m "merge with no-ff" dev
*/

/*bug分支*/
/*
Git还提供了一个stash功能，可以把当前工作现场“储藏”起来，等以后恢复现场后继续工作：

$ git stash
准备完成其他工作
git checkout dev回到分支
刚才的工作现场存到哪去了？用git stash list命令看看
一是用git stash apply恢复，但是恢复后，stash内容并不删除，你需要用git stash drop来删除；

另一种方式是用git stash pop，恢复的同时把stash内容也删了
*/
/*
Feature分支任务

git checkout -b feature-vulcan
5分钟后，开发完毕：
$ git add vulcan.py
$ git status
 git commit -m "add feature vulcan"
 git checkout dev
就在此时，接到上级命令，因经费不足，新功能必须取消！
虽然白干了，但是这个分支还是必须就地销毁：
git branch -d feature-vulcan//会报错
应用这个删$ git branch -D feature-vulcan
*/

//多人协作

//要查看远程库的信息，用git remote：
$ git remote
//用git remote -v显示更详细的信息：

//推送分支
 git push origin master
//推送其他分支，比如dev，就改成：
$ git push origin dev
//抓取分支
git clone git@github.com:michaelliao/learngit.git
//你的小伙伴要在dev分支上开发，就必须创建远程origin的dev分支到本地
git checkout -b dev origin/dev
//现在，他就可以在dev上继续修改，然后，时不时地把dev分支push到远程
git commit -m "add /usr/bin/env"
git push origin dev
//你的小伙伴已经向origin/dev分支推送了他的提交，而碰巧你也对同样的文件作了修改，并试图推送
//推送失败，因为你的小伙伴的最新提交和你试图推送的提交有冲突，解决办法也很简单，Git已经提示我们，
//先用git pull把最新的提交从origin/dev抓下来，然后，在本地合并，解决冲突，再推送：
git pull
//git pull也失败了，原因是没有指定本地dev分支与远程origin/dev分支的链接，根据提示，设置dev和origin/dev的链接：
git branch --set-upstream dev origin/dev
git pull
//这回git pull成功，但是合并有冲突，需要手动解决，
git commit -m "merge & fix hello.py"
git push origin dev

//创建标签

git branch
git checkout master
git tag v1.0//打一个新标签：
git tag//查看所有标签：

//如果忘了打标签
//找到历史提交的commit id，然后打上就可以了
git log --pretty=oneline --abbrev-commit
git tag v0.9 6224937
git tag
git show v0.9

//还可以创建带有说明的标签，用-a指定标签名，-m指定说明文字：
$ git tag -a v0.1 -m "version 0.1 released" 3628164
git show v0.1
//还可以通过-s用私钥签名一个标签：
$ git tag -s v0.2 -m "signed version 0.2 released" fec145a

//标签打错了，也可以删除：
 git tag -d v0.1

//如果要推送某个标签到远程，使用命令git push origin <tagname>：
git push origin v1.0
//一次性推送全部尚未推送到远程的本地标签
git push origin --tags

//标签已经推送到远程，要删除远程标签
git tag -d v0.9
git push origin :refs/tags/v0.9


/*使用github*/

//克隆了一个bootstrap仓库，然后，从自己的账号下clone：

git clone git@github.com:liukeyi77/bootstrap.git

//使用码云



















