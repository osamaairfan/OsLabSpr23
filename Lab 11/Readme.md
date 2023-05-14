# OS Lab 11
Name: M. Osama Irfan

Roll No: 21k-4772

Section: BCY-4A

# Task 1) Following and sumarizing the manual

### Installing squid

![squid1](https://user-images.githubusercontent.com/118754984/235299794-de51a816-044c-46f2-a4c1-9d4dc64e78ef.png)
![squid2](https://user-images.githubusercontent.com/118754984/235299795-5a98c1f1-cede-42bb-a068-2ac03a6b2e7f.png)
![squid3](https://user-images.githubusercontent.com/118754984/235299797-6f798fb2-48b4-4b20-8aa5-72c0221bdf45.png)
![squid4](https://user-images.githubusercontent.com/118754984/235299798-7bebe9d1-79cc-477c-98fd-156bc294c6fb.png)
![squid5](https://user-images.githubusercontent.com/118754984/235299799-f8b09f68-22a4-4d3a-aac8-2596ef32a76d.png)
---

### listing services

![list services](https://user-images.githubusercontent.com/118754984/235299801-8744d877-a941-4ff9-bb97-e4f63c3d1848.png)
---

### setting up unattended upgrades

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


# Task 2) Summarizing the manual

The lab focuses on implementing the best practices for improving the security of your Linux system. Starting with firewall and proxy configuration we set up Squid to block certain websites like Facebook and then set up a proxy to route all the traffic through Squid. 

Then we checked and disabled unnecessary services. And then ensured that our system was up to date, from software packages to the kernel. We also configured automatic updates.

We also used `ufw` (uncomplicated firewall), `nftables`, and `firewalld` to easily create rules and allow or block network traffic. 

Then, we looked at how we can implement strong password policies to ensure that all our passwords are complex enough to be safe from brute-force attacks. We also learned how to create new users and manage their groups and permissions using `chmod`, `chgrp`, `chown` and Linux Access Control Lists (ACLs). 

It is crucial to monitor system your system to ensure that no malicious activity has taken place and for that we learned how to check `syslog` and the currently and recently logged-in users using the `last` and `w` commands. At last we installed `auditd` and used the `auditctl` command to configure `auditd` and monitor system activity.

# Task 3, 4, 5, 6
```For any 3 tools describe in detail in you own words 
3. what they do?
4. How to affectively use them?
5. Any short-comings they might have?
6. Alternatives/Competitors they have?  
```
## Lynis
- Lynis is an open-source security auditing tool for Linux and Unix-based systems. It performs various tests to evaluate the security posture of the system, including checking for misconfigured services, open ports, and vulnerable packages.
- To use Lynis effectively, you should run it regularly and review its output to identify security weaknesses that need to be addressed. It's recommended to run it with root privileges to ensure it has access to all system files and settings.
- Lynis can produce a high volume of output, which can be overwhelming for some users. Also, some of the suggested fixes may not be feasible or appropriate for your specific system.
        Alternatives to Lynis include OpenVAS and Nessus.

## OpenSCAP
- OpenSCAP is an open-source security compliance scanning and monitoring tool for Linux-based systems. It provides a framework for checking and enforcing system security standards, such as those defined by the Center for Internet Security (CIS) benchmarks.
- To use OpenSCAP effectively, you should first determine which security standards you need to comply with and then configure OpenSCAP to run the appropriate checks. You can then automate the scanning and reporting process to ensure ongoing compliance.
- OpenSCAP may require a significant amount of configuration and customization to meet your specific needs. Also, some users may find the documentation to be complex or difficult to understand.
- Alternatives to OpenSCAP include CIS-CAT and Aqua Security's Kube-Bench.

## Nixarmor
- nixarmor is a Linux hardening tool that provides various security measures to protect against common attack vectors. It includes features such as process and network monitoring, file system protection, and kernel hardening.
- To use nixarmor effectively, you should first determine which security measures are most important for your system and then configure nixarmor accordingly. This may involve creating custom rules or policies for certain processes or applications.
- nixarmor may not be as well-known or widely used as some of the other tools on this list, which could make it more difficult to find support or troubleshooting help. Additionally, some users may find it challenging to configure or fine-tune the various security features.
- Alternatives to nixarmor include AppArmor and SELinux.
