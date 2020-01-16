<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Delete
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
        Me.Label1 = New System.Windows.Forms.Label
        Me.deleteButton = New System.Windows.Forms.Button
        Me.result1 = New System.Windows.Forms.Label
        Me.rolltext1 = New System.Windows.Forms.TextBox
        Me.cancButton = New System.Windows.Forms.Button
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(28, 26)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(53, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Enter Roll"
        '
        'deleteButton
        '
        Me.deleteButton.Location = New System.Drawing.Point(52, 61)
        Me.deleteButton.Name = "deleteButton"
        Me.deleteButton.Size = New System.Drawing.Size(75, 23)
        Me.deleteButton.TabIndex = 1
        Me.deleteButton.Text = "DELETE"
        Me.deleteButton.UseVisualStyleBackColor = True
        '
        'result1
        '
        Me.result1.AutoSize = True
        Me.result1.Location = New System.Drawing.Point(76, 110)
        Me.result1.Name = "result1"
        Me.result1.Size = New System.Drawing.Size(39, 13)
        Me.result1.TabIndex = 2
        Me.result1.Text = "Label2"
        '
        'rolltext1
        '
        Me.rolltext1.Location = New System.Drawing.Point(118, 23)
        Me.rolltext1.Name = "rolltext1"
        Me.rolltext1.Size = New System.Drawing.Size(100, 20)
        Me.rolltext1.TabIndex = 3
        '
        'cancButton
        '
        Me.cancButton.Location = New System.Drawing.Point(158, 61)
        Me.cancButton.Name = "cancButton"
        Me.cancButton.Size = New System.Drawing.Size(75, 23)
        Me.cancButton.TabIndex = 4
        Me.cancButton.Text = "CANCEL"
        Me.cancButton.UseVisualStyleBackColor = True
        '
        'Delete
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 262)
        Me.Controls.Add(Me.cancButton)
        Me.Controls.Add(Me.rolltext1)
        Me.Controls.Add(Me.result1)
        Me.Controls.Add(Me.deleteButton)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Delete"
        Me.Text = "Delete"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents deleteButton As System.Windows.Forms.Button
    Friend WithEvents result1 As System.Windows.Forms.Label
    Friend WithEvents rolltext1 As System.Windows.Forms.TextBox
    Friend WithEvents cancButton As System.Windows.Forms.Button
End Class
