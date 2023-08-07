Commande pour créer la Schedule Task : 

```Powershell
schtasks /create /tn "$scheduleTaskName" /sc onstart /delay 0000:30 /rl highest /ru system /tr "powershell.exe -file $powershellScriptPath"
```

Commande pour avoir les infos sur la Schedule Task : 

```Powershell
schtasks /Query /TN "$scheduleTaskName" /V /FO List
```

Commande pour supprimer la Task : 

```Powershell
schtasks /Delete /TN "$scheduleTaskName"
```
