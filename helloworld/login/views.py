from django.shortcuts import render, redirect
from django.contrib import messages
from . import models
from .forms import UserForm, RegisterForm, EditForm, PswchangeForm
from django.core.mail import send_mail

# Create your views here.
def info(request):
    if request.session.get('is_login', None):
        user = models.User.objects.get(name=request.session['user_name'])
        if request.method == "GET":
            return render(request, "login/info.html", {"user": user})
    return redirect('/logout/')

def edit(request):
    if request.session.get('is_login', None):
        user = models.User.objects.get(name=request.session['user_name'])

        if request.method == "POST":
            edit_form = EditForm(request.POST)
            message = "请检查填写内容"
            if edit_form.is_valid():
                user_cd = edit_form.cleaned_data
                user.email = user_cd['email']
                user.realname = user_cd['realname']
                user.tel = user_cd['tel']
                user.address = user_cd['address']
                user.sex = user_cd['sex']
                user.save()
                return render(request, "login/info.html", {"user": user})
        edit_form = EditForm(initial={'realname': user.realname, 'tel': user.tel, 'address': user.address, 'sex': user.sex,'email': user.email})

        return render(request, "login/edit.html", locals())



def index(request):
    pass
    return render(request, 'login/index.html')




def login(request):
    if request.session.get('is_login', None):
        return redirect('/index/')

    if request.method == "POST":
        login_form = UserForm(request.POST)
        message = "请检查填写的内容！"
        if login_form.is_valid():
            username = login_form.cleaned_data['username']
            password = login_form.cleaned_data['password']
            try:
                user = models.User.objects.get(name=username)
                if user.password == password:
                    request.session['is_login'] = True
                    request.session['user_id'] = user.id
                    request.session['user_name'] = user.name
                    return redirect('/index/')
                else:
                    message = "密码不正确！"
            except:
                message = "用户不存在！"
        return render(request, 'login/login.html', locals())

    login_form = UserForm()
    return render(request, 'login/login.html', locals())

def register(request):
    if request.session.get('is_login', None):
        return redirect('/index/')

    if request.method == "POST":
        register_form = RegisterForm(request.POST)
        message = '请检查填写的内容'
        if register_form.is_valid():
            username = register_form.cleaned_data['username']
            password1 = register_form.cleaned_data['password1']
            password2 = register_form.cleaned_data['password2']
            email = register_form.cleaned_data['email']
            sex = register_form.cleaned_data['sex']
            realname = register_form.cleaned_data['realname']
            address = register_form.cleaned_data['address']
            tel = register_form.cleaned_data['tel']
            #增加一些合法性验证
            if password2 != password1:
                message = '两次输入的密码不一致'
                return render(request, 'login/register.html', locals())
            else:
                same_name_user = models.User.objects.filter(name=username)
                if same_name_user:
                    message = '用户名已存在，请选择别的用户名'
                    return render(request, 'login/register.html', locals())
                same_email_user = models.User.objects.filter(email=email)
                if same_email_user:  # 邮箱地址唯一
                    message = '该邮箱地址已被注册，请使用别的邮箱！'
                    return render(request, 'login/register.html', locals())

                new_user = models.User.objects.create()
                new_user.name = username
                new_user.password = password1
                new_user.email = email
                new_user.sex = sex
                new_user.address = address
                new_user.tel = tel
                new_user.realname = realname
                new_user.save()
                messages.success(request, "注册成功")
                return redirect('/login/')
    register_form = RegisterForm()

    return render(request, 'login/register.html', locals())

def logout(request):
    if not request.session.get('is_login', None):
        return redirect('/index/')
    request.session.flush()
    messages.success(request, "登出成功")
    return render(request, 'login/index.html', locals())

def pswdchange(request):
    if not request.session.get('is_login', None):
        return redirect('/index/')
    if request.method=='POST':
        psw_form = PswchangeForm(request.POST)
        if psw_form.is_valid():
            origin_psw = psw_form.cleaned_data['password0']
            new_psw = psw_form.cleaned_data['password1']
            confirm_psw = psw_form.cleaned_data['password2']
            print(origin_psw)
            try:
                user = models.User.objects.get(name=request.session['user_name'])
                if user.password == origin_psw:
                    if new_psw == confirm_psw:
                        user.password = new_psw
                        user.save()
                        message = "密码修改成功！"
                    else:
                        message = "两次输入的密码不一致!"
                else:
                    message = "原密码输入错误!"
            except:
                message = "用户不存在!"
        return render(request,'login/index.html',locals())

    psw_form = PswchangeForm()
    return render(request,'login/index.html',locals())

def panel(request):
    if not request.session.get('is_login', None):
        return redirect('/index/')
    return render(request,'login/panel.html')
    
def misreport(request):
    if not request.session.get('is_login', None):
        return redirect('/index/')
    if request.method == 'POST':
        admin_name =  request.POST['admin_name']
        tel_num = request.POST['tel_num']           #用户手机
        mail_address = request.POST['mail_address'] #用户邮箱
        report_message = request.POST['report_message']        
        try:
            admin = models.Admin.objects.get(name=admin_name)
            admin_mail = admin.mail
        except:
            message = "该管理员不存在！"
            return render(request,'login/misreport.html',locals())
        try:
            subject = "报告错误:来自邮箱:" + mail_address +" 手机号: "+tel_num
            from_email = '978149308@qq.com'
            to = admin.mail
            send_mail(subject,report_message,from_email,[to])
            message = "错误提交成功"
            return render(request,'login/misreport.html',locals())
        except:
            message = "发送失败，请重新确认邮箱地址！"
            return render(request,'login/misreport.html',locals())
    return render(request,'login/misreport.html',locals())

def status(request):
    if not request.session.get('is_login', None):
        return redirect('/index/')
    s = socket.socket()
    addr = ''       #要连接的家庭装置的所在公网Ip
    port = 15535
    s.connect((addr,port))
    data = s.recv()
    sys_status = models.Syst.objects.get(name='sys')
    s.send(sys_status)
    s.close()
    if sys_status.status == 'on':
        message = "开"
    elif sys_status.status == 'off':
        message = "关"
    if request.method == 'POST':
        state = request.POST['sswitch']
        sys_status.status = sys_status
        sys_status.save()
        return render(request,'login/status.html',locals())
    return render(request,'login/status.html',locals())

