## GDDR6/GDDR6X GPU Memory Temperature Reader for Linux

Reads GDDR6/GDDR6X VRAM memory temperatures from multiple supported NVIDIA GPUs found in a host Linux system.
These findings are based on reverse engineering of the NVIDIA GPU Linux driver.

## ⚠️ AI Modified Code Disclaimer
This code has been forked and modified by an AI assistant. The human had no idea what he was doing. The modifications are provided "as is", without warranty of any kind, express or implied. Use at your own risk.

## Prerequisites

- Kernel boot parameter: iomem=relaxed

This step is optional. In some Linux distributions, the default kernel boot parameters are sufficient to run this program.

```
sudo vim /etc/default/grub
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash iomem=relaxed"
sudo update-grub
sudo reboot
```

- Disabling Secure Boot
  
This can be done in the UEFI/BIOS configuration or using [mokutil](https://wiki.debian.org/SecureBoot#Disabling.2Fre-enabling_Secure_Boot):

```
mokutil --disable-validation
```

Check state with:
```
$ sudo mokutil --sb
SecureBoot disabled
```

## Dependencies
- libpci-dev 
```
sudo apt install libpci-dev -y
```
## Build Without Installation
```
git clone https://github.com/uparseiparse/gddr6
cd gddr6
chmod +x build.sh
./build.sh
```

## Build With Installation
```
git clone https://github.com/uparseiparse/gddr6
cd gddr6
chmod +x build_install.sh
./build_install.sh
```

## Usage
```
sudo ./build/bin/gddr6
```

Output format:
```
GPU0: 60
```
Where the number after GPU indicates the device index, and the value is the temperature in Celsius.

## Integration
If you add this binary to your sudoers file it can run without password, which is probably not completely safe but sure is handy. The purpose of this fork was to allow simple piping into other programs for automation and monitoring.

e.g. 
sudo visudo
yourusername ALL=(ALL) NOPASSWD: /path/to/specific_command

## Supported GPUs
- RTX 4090 (AD102)
- RTX 4080 Super (AD103)
- RTX 4080 (AD103)
- RTX 4070 Ti Super (AD103)
- RTX 4070 Ti (AD104)
- RTX 4070 Super (AD104)
- RTX 4070 (AD104)
- RTX 3090 Ti (GA102)
- RTX 3090 (GA102)
- RTX 3080 Ti (GA102)
- RTX 3080 (GA102)
- RTX 3080 LHR (GA102)
- RTX 3070 (GA104)
- RTX 3070 LHR (GA104)
- RTX A2000 (GA106)
- RTX A4500 (GA102)
- RTX A5000 (GA102)
- RTX A6000 (AD102)
- L4 (AD104)
- L40S (AD102)
- A10 (GA102)

![](https://github.com/olealgoritme/gddr6/blob/master/gddr6_use.gif)
