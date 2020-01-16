<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Add
    Inherits _2_student.Main

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.saveButtton = New System.Windows.Forms.Button
        Me.cancelButton = New System.Windows.Forms.Button
        Me.nametext = New System.Windows.Forms.TextBox
        Me.addrtext = New System.Windows.Forms.TextBox
        Me.phonetext = New System.Windows.Forms.TextBox
        Me.deptcombo = New System.Windows.Forms.ComboBox
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label4 = New System.Windows.Forms.Label
        Me.result = New System.Windows.Forms.Label
        Me.SuspendLayout()
        '
        'saveButtton
        '
        Me.saveButtton.Location = New System.Drawing.Point(36, 193)
        Me.saveButtton.Name = "saveButtton"
        Me.saveButtton.Size = New System.Drawing.Size(75, 23)
        Me.saveButtton.TabIndex = 0
        Me.saveButtton.Text = "SAVE"
        Me.saveButtton.UseVisualStyleBackColor = True
        '
        'cancelButton
        '
        Me.cancelButton.Location = New System.Drawing.Point(181, 193)
        Me.cancelButton.Name = "cancelButton"
        Me.cancelButton.Size = New System.Drawing.Size(75, 23)
        Me.cancelButton.TabIndex = 1
        Me.cancelButton.Text = "CANCEL"
        Me.cancelButton.UseVisualStyleBackColor = True
        '
        'nametext
        '
        Me.nametext.Location = New System.Drawing.Point(117, 61)
        Me.nametext.Name = "nametext"
        Me.nametext.Size = New System.Drawing.Size(100, 20)
        Me.nametext.TabIndex = 2
        '
        'addrtext
        '
        Me.addrtext.Location = New System.Drawing.Point(117, 88)
        Me.addrtext.Name = "addrtext"
        Me.addrtext.Size = New System.Drawing.Size(100, 20)
        Me.addrtext.TabIndex = 3
        '
        'phonetext
        '
        Me.phonetext.Location = New System.Drawing.Point(117, 115)
        Me.phonetext.Name = "phonetext"
        Me.phonetext.Size = New System.Drawing.Size(100, 20)
        Me.phonetext.TabIndex = 4
        '
        'deptcombo
        '
        Me.deptcombo.FormattingEnabled = True
        Me.deptcombo.Items.AddRange(New Object() {"CIVIL", "CSE", "ETCE", "MECH"})
        Me.deptcombo.Location = New System.Drawing.Point(117, 34)
        Me.deptcombo.Name = "deptcombo"
        Me.deptcombo.Size = New System.Drawing.Size(121, 21)
        Me.deptcombo.TabIndex = 5
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(12, 37)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(101, 13)
        Me.Label1.TabIndex = 6
        Me.Label1.Text = "Choose Department"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(12, 64)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(63, 13)
        Me.Label2.TabIndex = 7
        Me.Label2.Text = "Enter Name"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(12, 91)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(73, 13)
        Me.Label3.TabIndex = 8
        Me.Label3.Text = "Enter Address"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(12, 118)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(66, 13)
        Me.Label4.TabIndex = 9
        Me.Label4.Text = "Enter Phone"
        '
        'result
        '
        Me.result.AutoSize = True
        Me.result.Location = New System.Drawing.Point(106, 159)
        Me.result.Name = "result"
        Me.result.Size = New System.Drawing.Size(32, 13)
        Me.result.TabIndex = 10
        Me.result.Text = "result"
        '
        'Add
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(292, 273)
        Me.Controls.Add(Me.result)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.deptcombo)
        Me.Controls.Add(Me.phonetext)
        Me.Controls.Add(Me.addrtext)
        Me.Controls.Add(Me.nametext)
        Me.Controls.Add(Me.cancelButton)
        Me.Controls.Add(Me.saveButtton)
        Me.Name = "Add"
        Me.Text = "Add"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents saveButtton As System.Windows.Forms.Button
    Friend WithEvents cancelButton As System.Windows.Forms.Button
    Friend WithEvents nametext As System.Windows.Forms.TextBox
    Friend WithEvents addrtext As System.Windows.Forms.TextBox
    Friend WithEvents phonetext As System.Windows.Forms.TextBox
    Friend WithEvents deptcombo As System.Windows.Forms.ComboBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents result As System.Windows.Forms.Label
End Class
