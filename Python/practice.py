ssh = paramiko.SSHClient()
ssh.connect(server, username=username, password=password)
ssh_stdin, ssh_stdout, ssh_stderr = ssh.exec_command(cmd_to_execute)