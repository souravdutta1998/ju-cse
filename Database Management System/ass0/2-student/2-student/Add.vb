Public Class Add
    Inherits Main
    Private Sub Add_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub

    Private Sub saveButtton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles saveButtton.Click
        Dim tempname, tempaddr, tempdept, tempdcode, temproll As String
        Dim temptotal, tempphone, idx As Integer
        tempname = nametext.Text
        tempaddr = addrtext.Text
        tempdept = deptcombo.Text
        tempphone = Val(phonetext.Text)

        If tempdept = "CIVIL" Then
            temptotal = arrDept(0).totalstudents + 1
            tempdcode = arrDept(0).dcode
            idx = 0
        ElseIf tempdept = "CSE" Then
            temptotal = arrDept(1).totalstudents + 1
            tempdcode = arrDept(1).dcode
            idx = 1
        ElseIf tempdept = "ETCE" Then
            temptotal = arrDept(2).totalstudents + 1
            tempdcode = arrDept(2).dcode
            idx = 2
        ElseIf tempdept = "MECH" Then
            temptotal = arrDept(3).totalstudents + 1
            tempdcode = arrDept(3).dcode
            idx = 3
        End If
        temproll = tempdcode & temptotal
        arrStu(idx, temptotal - 1).name = tempname
        arrStu(idx, temptotal - 1).roll = temproll
        arrStu(idx, temptotal - 1).dcode = tempdcode
        arrStu(idx, temptotal - 1).address = tempaddr
        arrStu(idx, temptotal - 1).phone = tempphone
        arrStu(idx, temptotal - 1).isDeleted = 0
        arrDept(idx).totalstudents = temptotal

        result.Text = temproll
    End Sub

    Private Sub cancelButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cancelButton.Click
        Me.Close()
    End Sub
End Class