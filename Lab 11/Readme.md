# OS Lab 11
Name: M. Osama Irfan

Roll No: 21k-4772

Section: BCY-4A

## Task 01:

### Installing squid

![squid1](https://user-images.githubusercontent.com/118754984/235299794-de51a816-044c-46f2-a4c1-9d4dc64e78ef.png)
![squid2](https://user-images.githubusercontent.com/118754984/235299795-5a98c1f1-cede-42bb-a068-2ac03a6b2e7f.png)
![squid3](https://user-images.githubusercontent.com/118754984/235299797-6f798fb2-48b4-4b20-8aa5-72c0221bdf45.png)
![squid4](https://user-images.githubusercontent.com/118754984/235299798-7bebe9d1-79cc-477c-98fd-156bc294c6fb.png)
![squid5](https://user-images.githubusercontent.com/118754984/235299799-f8b09f68-22a4-4d3a-aac8-2596ef32a76d.png)
---

### Listing services

![list services](https://user-images.githubusercontent.com/118754984/235299801-8744d877-a941-4ff9-bb97-e4f63c3d1848.png)
---

### Setting up unattended upgrades

![unattended upgrades](https://user-images.githubusercontent.com/118754984/235299802-42d5a90e-b0e6-4c5e-ac79-1e424e47b3d6.PNG)
---

### Staying up to date

![staying up to date](https://user-images.githubusercontent.com/118754984/235299804-0ea5993d-0956-41d4-b892-c97a69752658.PNG)
---

### Updating the Kernel

![updating kernel](https://user-images.githubusercontent.com/118754984/235299808-139838c2-0fb6-4688-9604-d21cbc6c253a.PNG)
---

### Setting up `ufw`

![ufw allowing http and https only](https://user-images.githubusercontent.com/118754984/235299811-e81c0546-f65b-4101-a8ac-535260518477.PNG)
---

### nftables

![nftables](https://user-images.githubusercontent.com/118754984/235299815-743332c4-e186-4d88-8f63-8cd76eadf261.PNG)
---

### Configuring nftables

![nftables config](https://user-images.githubusercontent.com/118754984/235299819-ca8b5f82-cf0a-479c-b9a6-71e00cff3467.PNG)
---

### Listing nft ruleset

![nft list ruleset](https://user-images.githubusercontent.com/118754984/235299823-84b60e43-fd57-4778-b4ac-cdf9f3fe5d5d.PNG)
---

### Implementing strong password practices

![strong password](https://user-images.githubusercontent.com/118754984/235299826-87f3e6b6-09b1-42ce-bc8f-6d0cb08c00ae.PNG)
![strong password logindefs](https://user-images.githubusercontent.com/118754984/235299828-151a314e-9957-488b-b601-7ff6712f2579.PNG)
![chage](https://user-images.githubusercontent.com/118754984/235299829-559af2dc-3a0f-43c3-8eef-f2ca1aeaad2d.PNG)
---

### Changing file ownership and permissions

![file ownership](https://user-images.githubusercontent.com/118754984/235299833-786940de-52f9-45f6-8f0b-b3123d38176a.PNG)
![changing file permissions](https://user-images.githubusercontent.com/118754984/235299836-6cd57ecd-5f96-438d-bbb9-d3d6916af8c2.PNG)
---

### Adding a low privilege user

![adding lowpriv user](https://user-images.githubusercontent.com/118754984/235299840-7e732481-18dd-4ff6-aa2f-ffafeeb0cac9.PNG)
---

### Adding the user to the sudoers list

![adding to sudo](https://user-images.githubusercontent.com/118754984/235299842-977b52d1-dbe4-4d26-96fb-b90c1cc7a2cf.PNG)
![visudo](https://user-images.githubusercontent.com/118754984/235299844-d91694fe-96d0-4dfe-9f13-e97f792262b9.PNG)
---

### Viewing the syslog

![syslog](https://user-images.githubusercontent.com/118754984/235299848-8b8b716d-10f7-461c-b6c5-9d8760572d6e.PNG)
---

### checking the previously logged in users

![last and w](https://user-images.githubusercontent.com/118754984/235299849-5dc2c5d4-5e41-46c0-a922-7f70581039e2.PNG)
---

### auditctl

![auditctl](https://user-images.githubusercontent.com/118754984/235299852-59f29e86-a518-4a49-b4b4-ffbec192c7c9.PNG)
---


## Task 02:

The lab's primary focus was on enhancing the security of a Linux system by implementing various best practices. Initially, we configured the firewall and proxy settings to block specific websites, such as Facebook, and redirected all traffic through Squid.

We ensured that the system was updated and all unnecessary services were disabled. Additionally, we used tools like ufw, nftables, and firewalld to create rules for network traffic.

To strengthen the system's security, we implemented strict password policies and learned how to create and manage users and their permissions using various Linux commands like chmod, chgrp, chown, and Access Control Lists (ACLs).

Moreover, monitoring the system is crucial to prevent any malicious activity, and we learned how to check syslog, currently and recently logged-in users using commands like last and w. Finally, we installed and configured auditd using the auditctl command to keep track of system activity.

## Task 03, 04, 05 & 06

### Lynis

Lynis is a security auditing tool for Unix and Linux-based systems that is available as open-source software. It runs various tests to evaluate the security status of the system, such as checking for misconfigured services, open ports, and vulnerable packages.

To utilize Lynis effectively, it is recommended to run it regularly with root privileges. It produces a substantial amount of output that can be challenging for some users to handle, and some of the suggested fixes may not be practical for specific systems. Other security auditing tools like OpenVAS and Nessus can be considered as alternatives.

### OpenSCAP

OpenSCAP is a security compliance monitoring and scanning tool for Linux-based systems that is also available as open-source software. It offers a framework for enforcing security standards, such as those defined by the Center for Internet Security (CIS) benchmarks.

To make the most of OpenSCAP, you should first determine the security standards you need to comply with and configure the tool accordingly. The process can be automated to ensure continuous monitoring and compliance. OpenSCAP has a complex configuration process and may require customization to meet your specific needs. Other tools like CIS-CAT and Aqua Security's Kube-Bench can be considered as alternatives.

### Nixarmor

Nixarmor is a Linux hardening tool that provides various security measures to protect against common attack vectors. Its features include process and network monitoring, file system protection, and kernel hardening.

To use Nixarmor effectively, you should first identify the security measures that are most important for your system and then configure the tool accordingly. This may involve creating custom rules or policies for specific processes or applications. Nixarmor is not as well-known or widely used as some of the other tools, making it harder to find support or troubleshooting help. Alternatives to Nixarmor include AppArmor and SELinux.
